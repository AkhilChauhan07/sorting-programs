#include<stdio.h>
#include<conio.h>
void merge(int a[],int lbeg,int mid,int rend)
{
    int c[rend+1];
    int i=lbeg;
    int j=mid+1;
    int k=lbeg;
    while (i<=mid && (j)<=rend)
    {
        if(a[i]<=a[j])
        {
            c[k]=a[i];
            i=i+1;
            k=k+1;
        }
        if(a[j]<=a[i])
        {
            c[k]=a[j];
            k=k+1;
            j++;
        }
    }
    while(i<=mid)
    {
        c[k]=a[i];
        i=i+1;
        k=k+1;
    }
    while(j<=rend)
    {
        c[k]=a[j];
        j++;
        k=k+1;
    }
    for(int i=lbeg;i<k;i++)
    {
        a[i]=c[i];
    }
}
void mergesort(int a[],int beg,int end)
{
    if(beg<end)
    {
        int mid=(beg+end)/2;
        mergesort(a,beg,mid);
        // int lbeg=beg;
        // int lend=mid;
        mergesort(a,mid+1,end);
        // int rbeg=mid+1;
        // int rend=end;
        merge(a,beg,mid,end);
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
    mergesort(arr,0,(n-1));
    display(arr,n);
}