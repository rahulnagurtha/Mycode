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
    int a[100005],temp,d,n,m,len,position;
    string b;
   	cin >> n >> m ;
	for (int i = 1; i <= n; ++i)
   	{
    	a[i]=readint();		
    }
    position=1;
    for (int i = 0; i < m; ++i)
    {
    	cin >> b ;
    	cin >> d ;
    	if(b[0]=='C')
    	{
    		temp=position+d;
    		if(temp>n) position=temp-n;
    		else position=temp;
    		continue;
    	}
    	if(b[0]=='A')
    	{
    		temp=position+(n-d);
    		if(temp>n) position=temp-n;
    		else position=temp;
    		continue;
    	}
    	if(b[0]=='R')
    	{
    		temp=position+(d-1);
    		if(temp>n) printf("%d\n",a[temp-n] );
    		else printf("%d\n", a[temp] );
    		continue;
    	}
    }
    return 0;
}
