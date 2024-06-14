#include <iostream>

using namespace std;
class d2;

class d1
{
    int cm, m;
public:
    void getdata()
    {
        cout<<"enter cm:"<<endl;
        cin>>cm;
        cout<<"enter m:"<<endl;
        cin>>m;
    }
friend void add(d1 o1, d2 o2);

};

class d2
{
    int inch, ft;
public:
    void getdata()
    {
        cout<<"enter inch:"<<endl;
        cin>>inch;
        cout<<"enter feet:"<<endl;
        cin>>ft;
    }
friend void add(d1 o1, d2 o2);
};

void add(d1 o1, d2 o2)
{
    int d1_inches = o1.cm*0.3937  + o1.m*39.37;
    int total_inches = d1_inches +o2.inch+o2.ft*12;
    cout<<total_inches%12<<" feet"<<total_inches/12<<" inches ";
}

int main()
{
    d1 a1;
    a1.getdata();
    d2 a2;
    a2.getdata();
    add(a1,a2);
}
