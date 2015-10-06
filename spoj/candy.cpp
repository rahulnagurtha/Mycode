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
int main()
{
    while(1)
    {
        int num,count=1;
        int a[1002];
        cin >> num ;
        int count2;
        count2=num;
        if(num==0) break;
        for (int i = 0; i < num; ++i)
        {
            a[i]=readint();
        }
        int flag=1;
        for (int i = 0; i < num ; ++i)
        {
            if(a[i]==count) count++;
            else
            {
                if(a[i]!=count2) 
                {
                        printf("no\n");
                        flag=0;
                        break;
                }
                count2--;
            }
        }
        if(flag==1) printf("yes\n");
    }
    return 0;
}

     