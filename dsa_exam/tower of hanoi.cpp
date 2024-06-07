#include <iostream>

using namespace std;

void tower_of_hanoi(char s, char d, char a, int n)
{
    if(n==1)
    {
        printf("move disk from %c to %c \n",s,d);
    }
    else{
        tower_of_hanoi(s,a,d,n-1);
        printf("move disk from %c to %c \n",s,d);
        tower_of_hanoi(a,d,s,n-1);
    }
}
int main()
{
    tower_of_hanoi('a','c','b',3);
    return 0;
}
