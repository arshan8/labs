#include <stdio.h>

int bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void print(int arr[], int n)
{
    for(int i =0; i<n;i++)
    {
        printf("%d \t", arr[i]);
    }
}
 int main()
 { int q[20] = {4,2,6,9};
  int o = 4;
  bubble_sort(q,o);
  print(q,o);
 return 0;
 }
