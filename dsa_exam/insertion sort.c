#include <stdio.h>
#include <stdlib.h>


void insertion_sort(int arr[], int n)
{
    for(int i =1;i<n;i++)
    {
        int k = arr[i];
        int j = i-1;
        for(j;j>=0;j--)
        {
            if(k<arr[j])
            {
                arr[j+1] = arr[j];

            }
            else
            {
                break;
            }

        }
        arr[j+1]=k;
    }

}
void printarr(int arr[],int n)
{
     for(int i =0;i<n;i++)
    { printf("%d \t",arr[i]);
    }
}
int main()
{ int q[100]={16,4,9,3,5,999,-41};
    int n = 7;
    insertion_sort(q,n);
    printarr(q,n);
    return 0;
}
