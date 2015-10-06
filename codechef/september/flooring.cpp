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
#include <time.h>
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
        clock_t t;
        double ans1;
    	long long int N,M,ans=0,temp1,temp2,temp3;
    	scanf("%lld%lld",&N,&M);
        t=clock();
    	for (long long int i = 1; i <= N ; ++i)
    	{
    		temp1=N/i;
    		temp2=((i%M)*(i%M)*(i%M)*(i%M))%M;
    		temp3=(temp1*temp2)%M;
    		ans=ans+temp3;
    		ans=ans%M;
    	}
        t=clock()-t;
        ans1=(double)t/CLOCKS_PER_SEC;
        printf("%lf is time taken\n",ans1);
    	printf("%lld\n", ans);
    }
    return 0;
}