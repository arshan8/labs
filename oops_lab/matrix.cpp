#include<iostream>

using namespace std;

class matrix
{
    long m[5][5];
    int row,col;

public:
    void getdata();
    friend ostream &operator<<(ostream&, matrix&);
    matrix operator+(matrix a);
    matrix operator-(matrix a);
};

void matrix::getdata()
{
    cout<<"enter row:"<<endl;
    cin>>row;
    cout<<"enter columb"<<endl;
    cin>>col;

    cout<<"enter data"<<endl;
    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>m[i][j];
        }
    }
}

matrix matrix::operator+(matrix a)
{
    matrix temp;
    for(int i = 0;i<a.row;i++) // can be simply row instead of a.row;
    {
        for(int j =0;j<a.col;j++)
        {
            temp.m[i][j]=m[i][j]+a.m[i][j];
        }
    }
    temp.row = row;
    temp.col = col;
    return temp;
}


matrix matrix::operator-(matrix a)
{
    matrix temp;
    for(int i = 0;i<a.row;i++) // can be simply row instead of a.row;
    {
        for(int j =0;j<a.col;j++)
        {
            temp.m[i][j]=m[i][j]-a.m[i][j];
        }
    }
    temp.row = row;
    temp.col = col;
    return temp;
}
ostream &operator<<(ostream &fout, matrix &d)
{
     for(int i = 0;i<d.row;i++)
    {
        for(int j=0;j<d.col;j++)
        {
            fout<<d.m[i][j]<<" ";
        }
        fout<<" \n";
    }
}

int main()
{
    matrix m1,m2;
    m1.getdata();
    m2.getdata();

   cout<<"sum is :"<<endl;
    matrix m3;
    m3 = m1+m2;
    cout<<m3;

   cout<<"difference:"<<endl;

    m3 = m1-m2;
    cout<<m3;

    return 0;
}
