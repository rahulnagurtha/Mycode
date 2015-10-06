#include <stdio.h>
int main()
{
	int marks[52],a[1000];
	int num,i,j,k;
	for ( i = 0; i < 51; ++i)
	{
		marks[i]=0;
	}
	printf("number of students: ");
	scanf("%d",&num);
	printf("enter their marks:\n");
	for ( i = 0; i < num; ++i)
	{
		scanf("%d",&a[i]);
		marks[a[i]]++;
	}
	for ( i = 2; i < 51; ++i)
	{
		marks[i]=marks[i-1]+marks[i];
	}
	printf("enter a and b  (  a<b  ) ?\n");
	int c,b;
	scanf("%d%d",&c,&b);
	printf("%d\n",marks[b]-marks[c-1]);
	return 0;
}