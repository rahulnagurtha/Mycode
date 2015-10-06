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
int primes[664580];
int main()
{
	//sieve
	int temp,cnt,cnt1;
    primes[0]=2,primes[1]=3;
    //printf("upto which number ?\n");
    //scanf("%d",&number);
    cnt1=1;
    for (int i = 5; i <= 9999991 ; i+=2)
    {
       	temp=(int)sqrt(i);
       	cnt=0;
       	for (int j = 1 ; primes[j]<= temp ; ++j)
       	{
       		if(i%primes[j]==0)
       		{
       			cnt++;
       			break;
       		}
       	}
       	if(cnt==0)
       	{
       	    cnt1++;
       		primes[cnt1]=i;
       	}
    }

    int test;
    cin >> test ;
    while(test--)
    {
    	long long int temp1,count=0,num=0;
		stack<long long int> factors;
		string a;
		cin >> a ;
		//converting it into number
		if(a.size()<18){
			for (int i = 0; i < a.size(); ++i){
				temp1=(int)(a[i]-'0');
				num=num*10+temp1;
			}


			for (int i = 0; i <= 9999991 ; ++i)
			{
				if(num==1) break;
				while(num%primes[i]==0)
				{
					count++;
					num=num/primes[i];
					factors.push(primes[i]);
				}
			}
			if(num!=1) {
				count++;
				factors.push(num);
			}
			cout << count << endl ;
			while (!factors.empty())
			{
				cout << factors.top() << endl ;
				factors.pop();
			}
		}
		else cout << "1" << "\n" << a << endl ;
	}
	return 0;
}











