#include<stdio.h>
#include<conio.h>
int getmax(int a[],int n)
{
    int max=a[0];
    for(int i=0;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    return max;
}
void countingsort(int a[],int n,int pos)
{
    int count[10]={0};//initialize all element of count array to 0
    for(int i=0;i<n;i++)
    {
        count[(a[i]/pos)%10]++;//unit place item is place in count according to its reminder in count array
    }
    for(int i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    int output[n];
    for(int j=n-1;j>=0;j--)
    {
        output[--count[(a[j]/pos)%10]]=a[j];
    }
    //put output array in original array
    for(int i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}
void radixsort(int a[],int n)
{
    int max=getmax(a,n);
    for(int pos=1;max/pos>0;pos=pos*10)
    {
        countingsort(a,n,pos);
    }
}
void display(int a[],int n)
{
    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void main(){
    int arr[26];
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter the element A[%d]=",i);
        scanf("%d",&arr[i]);
    }
    radixsort(arr,n);
    display(arr,n);
}