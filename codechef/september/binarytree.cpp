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
using namespace std;

#define mod 1000000007

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
    	string a;
    	cin >> a ;
    	long long int ans=1,temp=1;
    	int len=a.size();
    	for (int i = 0; i < len ; ++i)
    	{
    		if(a[i]=='l')
    		{
    			if(temp%2==0)
    			{
    				ans=ans*2-1;
    				temp=ans%2;
    				ans=ans%1000000007;
    			}
    			else
    			{
    				ans=ans*2;
    				temp=ans%2;
    				ans=ans%1000000007;
    			}
    		}
    		if(a[i]=='r')
    		{
    			if(temp%2==0)
    			{
    				ans=(ans*2-1)+2;
    				temp=ans%2;
    				ans=ans%1000000007;
    			}
    			else
    			{
    				ans=ans*2+2;
    				temp=ans%2;
    				ans=ans%1000000007;
    			}
    		}
    	}
    	printf("%lld\n",ans);
    }
    return 0;
}