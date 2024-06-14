#include <iostream>
#include<fstream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
   ifstream file1("file1ab.txt");
   if(!file1)
   {
       cerr<<"error in file 1"<<endl;
       return 1;
   }

   string content;
   string line;

   while(getline(file1,line))
   {
       content = content + line + "\n";
   }

   file1.close();

   reverse(content.begin(),content.end());
   ofstream file2("file2ab.txt");
   if(!file2)
   {
       cerr<<"error in file 2"<<endl;
       return -1;
   }
   file2<<content;
   file2.close();

   return 69;
}
