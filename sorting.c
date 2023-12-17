#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int arr[20];
void createarray(int n)
{

    for(int i=0;i<n;i++)
    {
        printf("A[%d]=",i);
        scanf("%d",&arr[i]);
    }
}
void bubblesort(int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<(n-i-1);j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
} 
void selectionsort(int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
           if(arr[i]>arr[j])
           {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
           } 
        }
    }
}
void display(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void insertionsort(int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            {
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}
void main()
{
    int n,choice;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    createarray(n);
    printf("SOrting techniques:\n");
    while(1)
    {
        printf("\n1.bubble sort\n2.selection sort\n3.insertion sort\n4.display\n5.quit\n");
        printf("ENter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
            bubblesort(n);
            break;
            }
            case 2:
            {
                selectionsort(n);
                break;
            }
            case 3:
            {
                insertionsort(n);
                break;
            }
            case 4:
            {
                display(n);
                break;
            }
            case 5:
            {
                exit(0);
            }
            default:
            printf("Wrong choice\n");
        }
    }
}