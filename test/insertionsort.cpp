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
    	int a[100],temp1,len,i,j,k,temp;
    	printf("enter the number of elements in the array:\n");
    	scanf("%d",&len);
    	printf("enter the array elements:\n");
    	for (i = 0; i < len; ++i)
    	{
    		scanf("%d",&a[i]);
    	}
    	for (i = 1; i < len; ++i)
    	{
    		temp1=i;
    		for (j = i-1; j >=0 ; --j)
    		{
    			if(a[j]>a[temp1]) 
    			{
    				swap(a[j],a[temp1]);
    				temp1=j;
    			}		
    		}
    	}
    	printf("the sorted array is :\n");
    	for (int i = 0; i < len; ++i)
    	{
    		printf("%d ",a[i]);
    	}
    	printf("\n\n");
    }
    return 0;
}






