#include <stdio.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <string>
using namespace std;
int primes[664580];
int main()
{
        int test;
        scanf("%d",&test);
        while(test--)
        {
        	int temp,number,cnt,cnt1;
        	primes[0]=2,primes[1]=3;
        	printf("upto which number ?\n");
        	scanf("%d",&number);
        	cnt1=1;

        	for (int i = 5; i <= number ; i+=2)
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
        	long long int sum=0;
        	printf("the primes upto the entered number are:\n");
        	for (int i = 0; i <= cnt1 ; ++i)
        	{
        		printf("%d--->%d\n",i,primes[i]);
        		sum=sum+primes[i];
        	}
        	printf("sum=%lld\n",sum);
        }
}
