#include <stdio.h>

int a[100];
int a1[100];

void task(int start,int end);
void merge(int s1,int e1,int s2,int e2);
int main()
{
	int i,j,k,temp,len;
	printf("number of elements in array:\n");
	scanf("%d",&len);
	printf("enter the elements:\n");
	for (int i = 0; i < len; ++i)
	{
		scanf("%d",&a[i]);
	}

	task(0,len-1);

	for (int i = 0; i < len; ++i)
	{
		printf("%d ",a[i]);
	}
}


void task(int start,int end)
{
	int temp,num1,num2,i,j,k,len;
	len=(end-start+1)/2;
	if(start!=end)
	{
		printf("calling task(%d,%d)\n\n",start,start+len-1);
		task(start,start+len-1);
		printf("calling task(%d,%d)\n\n",start+len,end);
		task(start+len,end);
		printf("calling merge(%d,%d,%d,%d)\n\n",start,start+len-1,start+len,end);
		merge(start,start+len-1,start+len,end);
	}
}

void merge(int s1,int e1,int s2,int e2)
{
	int count=0,i,j,k;
	for (int i = s1,j=s2;(i<=e1 || j<=e2);)
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
				a1[count]=a[i];
				count++;
				i++;
			}
		}
	}
	count=0;
	for (int i = s1; i <= e2; ++i)
	{
		a[i]=a1[count++];
	}
}








