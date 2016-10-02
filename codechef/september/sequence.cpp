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
#include <utility>

using namespace std;
#define inf 1000000005 
int first=inf,second=inf;

bool isbeauty(int a,int b)
{
	if(first==inf && second==inf) return 1;
	if(first < a) return 0;
	else
	{
		if(a<first) return 1;
		else
		{
			if(b<second) return 1;
		}
	}
}


int main()
{
    int array[100005],temp,limit,N,K,a,d,flag,count;
    
    //read input
    cin >> N >> K ;
    for (int i = 1; i <= N; i++) cin >> array[i];

    //finding limit to check
    if (N>12) limit=12;
	else limit=N;

	//generating all possible combinations
 	for (int i = 1; i <=limit; ++i)
	{
		for (int j = i+1; j <= limit; ++j)
		{
			count=K;
			temp=array[j]-array[i];
			if((temp%(j-i))!=0) continue;
			d=temp/(j-i);
			a=array[i]-(i-1)*d;
			if(!(isbeauty(a,d))) continue;
			flag=1;
			for (int k = 1; k <= N; ++k)
			{
				temp=a+(k-1)*d;
				if(array[k]!=temp) 
					{
						if(count>0) count--;
						else 
							{
								flag=0;
								break;
							}
					}		
			}
			if(flag==1) {
				first=a;
				second=d;
			}
		}
	}
	a=first;
	d=second;
	for (int i = 1; i <=N; ++i)
	{
		cout << a+(i-1)*d << " ";
	}
    return 0;
}

```