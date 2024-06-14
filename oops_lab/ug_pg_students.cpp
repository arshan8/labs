#include <iostream>

using namespace std;


class student
{
    int usn;
    string name;
public:
    int age;
    void getdata()
    {
        cout<<"enter name:"<<endl;
        cin>>name;
          cout<<"enter age:"<<endl;
        cin>>age;
          cout<<"enter usn:"<<endl;
        cin>>usn;

    }
    void showdata()
    {
        cout<<" name is "<< name<<" us is "<<usn<<" age is "<<age<<endl;
    }
};

class ugstudent:public student
{
    int fees;
public:
int sem;
    void uggetdata()
    {
        getdata();
        cout<<"enter fees:"<<endl;
        cin>>fees;
        cout<<"enter sem:"<<endl;
        cin>>sem;
    }
    void ugshowdata()
    {
        showdata();
        cout<<" fees is "<<fees<<" sem is "<<sem;
    }
};

int main()
{int n;
    ugstudent a1[10];
    cout<<"enter total ug students:"<<endl;
    cin>>n;
    for(int i =0;i<n;i++){
    a1[i].uggetdata();
    cout<<"\n \n";
    }
    int semu = 5;
    int total = 0;
    int c =0;
    for(int i =0;i<n;i++)
    {
        if(a1[i].sem==semu)
        {
           total += a1[i].age;
           c++;
        }
    }
    cout<<"average age for "<<semu<<" is "<<total/c;


    //a1.ugshowdata();

    return 9;
}
