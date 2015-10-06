#include <stdio.h>
#include <iostream>
using namespace std;
int a[100],num;
void task(int start,int end)
{
	int temp=end-start+1;
	int position=start+temp/2;
	else if(start==end)
	{
		if(a[start]==num) printf("value found at index %d\n",start+1);
		else printf("value not found\n");
	}
	else
	{
		if(a[position]==num) printf("value found at index %d\n",position+1 );
		else if(a[position]>num) {printf("calling (%d,%d)\n",start,position-1 ); task(start,position-1);}
		else {printf("calling (%d,%d)\n",position+1,end ); task(position+1,end);}
	}
}

int main()
{
	//int a[10];
	int len;
	printf("number of elements: ");
	scanf("%d",&len);
	for (int i = 0; i < len; ++i)
	{
		a[i]=i+1;
		cout << a[i] << " " ;
	}
	printf("\n");
	//int num;
	printf("value to be found: ");
	scanf("%d",&num);
	task(0,len-1);
}