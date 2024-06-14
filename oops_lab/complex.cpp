#include <iostream>

using namespace std;

class complex
{
    int real,imag;

public:

    complex()
    {
       real=imag=0;
    }

    complex(float a, float b)
    {
        real = a;
        imag = b;
    }
    complex(int a)
    {
        real = a;
        imag = 0;
    }

    complex add(complex b)
    {
        complex res;
        res.real = real+b.real;
        res.imag = imag+b.imag;
        return res;
    }

    complex add(int a)
    {
        complex res;
        res.real = real + a;
        res.imag = imag;
        return res;
    }

    void display()
    {
        if(imag>0)
        {
            cout<<real<<"+i"<<imag<<endl;
        }
        else
        {
            cout<<real<<"-i"<<imag<<endl;
        }
    }
};

int main()
{
    complex c1(3,4);
    complex c2(3,3);
     c1.display();
     c2.display();
     complex c3;
     c3 = c2.add(c1);
     cout<<"adding c1 and c2 : ";
     c3.display();
     complex c4;
     c4 = c2.add(5);
    cout<<"adding 5 to c2 : ";
     c4.display();
     return 0;
}
