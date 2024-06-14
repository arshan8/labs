#include <iostream>

using namespace std;

class student
{
private:
    int regno;
    string name;
    int sem;
    string branch;

public:
  //  student(int r, string s, int n, string b): regno(r), name(s), sem(n),branch(b){}
    student(){};
    void getdata()
    {
        cout<<"\n enter name:";
        cin>>name;
         cout<<" \n enter roll:";
        cin>>regno;
         cout<<"\n enter sem:";
        cin>>sem;
         cout<<"\n enter branch:";
        cin>>branch;
    }
    void showdata()
    {
        cout<<" name is "<<name<<" roll no: "<<regno<<" in sem : "<<sem<<" branch : "<<branch<<endl;
    }
};

class exams : virtual public student
{
    int marks1,marks2;

public:
  //  exams(int r, string s, int n ,string b, int m1, int m2): student(r,s,n,b),marks1(m1),marks2(m2){}
    exams(){}

    void examsgetdata()
    {
        cout<<"enter marks 1";
        cin>>marks1;
        cout<<"enter marks 2";
        cin>>marks2;
    }
  void examsshowdata()
{
    cout<<"\n marks 1 are "<<marks1<<" marks 2 are "<<marks2<<endl;
}
};

class sports:virtual public student
{
    char grade;
public:
   // sports(int r, string s, int n, string b, char a):student(r,s,n,b),grade(a){}
    sports(){}

    void sportsgetdata()
    {
       cout<<"enter sports grade "<<endl;
       cin>>grade;
    }
    void sportsshowdata()
    {
        cout<<"\n sports grade:"<<grade;
    }
};

class awards:public exams, public sports
{
public:
   // awards(int r,string s,int n, string b, int m1, int m2, char a):student(r,s,n,b),exams(r,s,n,b,m1,m2),sports(r,s,n,b,a){}
    awards(){}

    void getfina()
    {
        getdata();
        examsgetdata();
        sportsgetdata();
    }
    void showfina()
    {
        showdata();
        examsshowdata();
        sportsshowdata();
    }

};

int  main()
{
   awards a1;
   a1.getfina();
   a1.showfina();
   return 0;
}
