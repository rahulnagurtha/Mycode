#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int LL;

int a[10000];
int a1[10000];

LL invcount;


//creating two funtions t odivide and merging respectively
void divide(int start,int end);
void merge(int s1,int e1,int s2,int e2);

int main()
{
	int iter;
	cin >> iter ;
	while(iter--) {
		invcount=0;
		int i,j,k,temp,len;
		double ans;
		scanf("%d",&len);
		//taking the input
		for (i = 0; i < len; ++i)
		{
			scanf("%d",&a[i]);
		}
		getchar();
		getchar();
		divide(0,len-1);
		printf("%lld\n",invcount);
	}
	return 0;
}



void divide(int start,int end)
{
	int temp,num1,num2,i,j,k,len;
	len=(end-start+1)/2;
	if(start!=end)
	{
		divide(start,start+len-1);
		divide(start+len,end);
		merge(start,start+len-1,start+len,end);
	}
}



//merging of two sorted arrays by keeping the variable pointing to each of the first lements

void merge(int s1,int e1,int s2,int e2)
{
	int count=0,i,j,k;
	for (i = s1,j=s2;(i<=e1 || j<=e2);)
	{
		if(i<=e1 && j<=e2)
		{
			if(a[i]<=a[j])
			{
				a1[count]=a[i];
				i++;
				count++;
			}
			else
			{
				invcount+=(LL)e1-(LL)i+1;
				a1[count]=a[j];
				j++;
				count++;
			}
		}
		else
		{
			if(i>e1)
			{
				a1[count]=a[j];
				count++;
				j++;
			}
			else
			{
				invcount+=(LL)e2-(LL)s2+1;
				a1[count]=a[i];
				count++;
				i++;
			}
		}
	}
	count=0;
	for (i = s1; i <= e2; ++i)
	{
		a[i]=a1[count++];
	}
}








