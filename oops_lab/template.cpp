#include <iostream>

using namespace std;

template<class T>

T suc(T x)
{
    return x+1;
}

template<class X>

int sum(X arr[],int s)
{ int total;
    for(int i =0; i<s;i++)
    {
      total = total + arr[i];
    }
    return total;
}

int main()
{
  cout<<"successor of int:"<< suc(2)<<endl;
  cout<<"successor of char:"<< suc('a')<<endl;
  cout<<"successor of float:"<< suc(3.3)<<endl;

  int int_arr[]={5,5,5,5,5};
  float f_arr[]={1.1,2.2,3.1,4.1,5.2};

  int int_a = sum(int_arr,5);
  float f_a= sum(f_arr,5);

cout<<"\n \t"<<int_a<<"\t"<<f_a;
  return -69;
}
