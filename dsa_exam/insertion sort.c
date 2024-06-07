#include <stdio.h>
#include <stdlib.h>


void insertion_sort(int arr[], int n)
{
    for(int i =1;i<n;i++)
    {
        int k = arr[i];
        int j = i-1;
        for(int s = j;s>=0;s--)
        {
            if(k<arr[j])
            {
                arr[s+1] = arr[s];
                j--;
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
{ int q[100]={16,4,9,3,5};
    int n = 5;
    insertion_sort(q,n);
    printarr(q,n);
    return 0;
}
