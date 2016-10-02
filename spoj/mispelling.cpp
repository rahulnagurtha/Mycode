#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;


// fast input

#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
int readint()
{
register char c=gc();
while(c<'0'||c>'9')
    c=gc();  //ignore all characters till the first digit
int ret=0;
while(c>='0' && c<='9') //till we get a stream of digits.As soon as we get something else,we stop
{
ret=ret*10+(c-48);//construct the number
c=gc();
}
return ret;
}


// main code begins now

map<long long,unsigned long long> mymap;

unsigned long long max(long long n,unsigned long long k)
{
     return ((n>k)?n:k);
}

unsigned long long int f(long long n)
{
         if(n==0)
         return 0;
         
         unsigned long long int a=mymap[n];
     
         if(a==0)
         {
                 unsigned long long int a=max(n,f(n/2)+f(n/3)+f(n/4));
                 mymap[n]=a;
         }
     
         return a;
     
}

int main()
{
    long long n,t=10;
    
    mymap.clear();
    
    while(t--)
    {
              n=readint();
              unsigned long long int b=f(n);
              
              cout<<b<<endl;
              
    }
    
    system ("pause");
    
    return 0;
    
}
