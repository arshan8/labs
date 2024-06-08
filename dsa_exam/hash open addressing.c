#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a student
int main()
{
    int a[20], hash[20];
    int n;
    printf("enter no. of elements:");
    scanf("%d",&n);
    printf("enter elements:");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<20;i++)
    {
       hash[i]=-1;
    }
    for(int i = 0;i<n;i++)
    {
       int key = a[i]%10;
        if(hash[key]==-1)
        {
            hash[key]=a[i];
            printf("\n hash[%d]---->%d",key,a[i]);

        }
        else{

            int j = key+1;
            while(1)
            {
                if(j>20)
                {
                    j=-1;            //because it will be set to 0 anywhow because j++ is there down V
                }                                                                                 // V
                if(hash[j]==-1)
                {
                   hash[j] = a[i];
                    printf("\n hash[%d]---->%d",j,a[i]);
                    break;
                }
                j++;                                                                              // <<^
            }
        }
    }




return -69;
}
