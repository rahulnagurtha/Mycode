#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
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
    int test;
    test=readint();
    while(test--)
    {
        int a[11];
        int temp,position,small;
        printf("enter the array:\n");
        for (int i = 0; i < 10; ++i)
        {
            scanf("%d",&a[i]);
        }
        for (int i = 0; i < 9; ++i)
        {
            small=a[i];
            position=i;
            for (int j = i; j < 10; ++j)
            {
                if(a[j]<=small)
                {
                    small=a[j];
                    position=j;
                }
            }
            a[position]=a[i];
            a[i]=small;
        }

        for (int i = 0; i < 10; ++i)
        {
            cout << a[i] << " " ;
        }
        printf("\n");
    }
    return 0;
}