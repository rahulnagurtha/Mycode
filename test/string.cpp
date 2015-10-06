#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <limits>
#include <string>
#include <conio.h>
using namespace std;
int main()
{
        int test;
        scanf("%d",&test);
        while(test--)
        {
            int i,j,k;
            string a,b,c;
            a="hello i am rahul";
            b=a.substr(0,5);
            c=b+" "+"mubassir"+" "+b.substr();
            cout << a << "\n" ;
            cout << b << "\n" ;
            cout << c << "\n" ;
            a.insert(0,"mubassir ");
            cout << a << endl ;
            string base="this is a test string.";
            string str2="n example ";
            string str=base;                // "this is a test string."
            str.replace(9,5,str2);
            cout << str <<"\n";
            i=a.find("am");
            cout << i <<"\n";
            replace(a.begin(),a.end(),'a','x');
            cout << a << endl ;
            i=str2.length();
            cout << i << endl;
            i=str2.find_first_not_of(" ");
            cout << i << endl;
       }
}
