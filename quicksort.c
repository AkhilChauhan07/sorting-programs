#include<stdio.h>
#include<conio.h>
void quick(int a[],int beg,int end,int *loc)
{
    //fixing of elements
        int left=beg;
        int right=end;
        (*loc)=beg;
        ccc:
        while(a[right]>=a[*loc] && *loc!=right)
        {
            right=right-1;
        }
        
        if(*loc==right)
        {
            return;
        }
        if(a[right]<a[*loc])
        {
            int temp=a[*loc];
            a[*loc]=a[right];
            a[right]=temp;
            *loc=right;
        }
        while(a[left]<=a[*loc] && *loc!=left)
        {
            left=left+1;
        }
        if(*loc==left)
        {
            return;
        }
        if(a[left]>a[*loc])
        {
            int temp=a[*loc];
            a[*loc]=a[left];
            a[left]=temp;
            *loc=left;
        }
        
        goto ccc;
}
void qiucksort(int a[],int n){
    int top=-1,loc,beg,end,left,right;
    int lower[10],upper[10];
    top++;
    lower[top]=0;
    upper[top]=n-1;
    while(top!=-1)
    {
        left=beg=lower[top];
        right=end=upper[top];
        top--;
        quick(a,beg,end,&loc);
        if(beg<loc-1)
        {
            top++;
            lower[top]=left;
            upper[top]=loc-1;
        }
        if(end>loc+1)
        {
            top++;
            lower[top]=loc+1;
            upper[top]=right;
        }
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
    qiucksort(arr,n);
    display(arr,n);
}