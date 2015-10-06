#include <stdio.h>
#include <string.h>

/*
	my program assumes all the input letters are in lower case letters,
	so that it wil be convinient to sort them irrespective of whether
	they are lower case or upper case.
*/

/*
	algorithm:
		the idea of the algorithm is applying radix sort which is nothing but
		applying count sort repeatedly...........
*/

char a[1000][50];
char b[1000][50];
int len,count[130],max=0;


void task()
{
	int i,j,k,temp;

	//applying count sort over each position starting from last position
	for (i = max-1; i>=0 ; --i)
	{
		//applying count sort over last letter in each word
		for (j = 0; j < len  ; ++j)
		{
			temp=(int)a[j][i];
			count[temp]++;
		}

		//finding cumulative frequency
		for (j = 1; j < 130; ++j) count[j]+=count[j-1];

		//changing the order of words depending on the above cumulative frequency
		for (j = len-1; j>=0 ; --j)
		{
			temp=(int)a[j][i];
			//copying into the new array
			strcpy(b[count[temp]-1],a[j]);
			count[temp]--;
		}

		//copying into the original array
		for (j = 0; j < len; ++j)
		{
			strcpy(a[j],b[j]);
		}

		//setting back the counts to zero beacuse we have to apply count sort freshly again
		for (j = 0; j < 130 ; ++j)
		{
			count[j]=0;
		}
	}
	return;
}


int main()
{
	int i,j,k,temp;
	printf("number of words:");
	scanf("%d",&len);
	getchar();

	//setting all the characters to '\0'
	for ( i=0; i < len; ++i)
	{
		 memset( a[i],'\0', 50 );
	}
	

	//taking input
	printf("enter the words \n");
	for ( i = 0; i < len; ++i)
	{
		gets(a[i]);
		if(strlen(a[i]) > max) max=strlen(a[i]);
	}


	//calling function
	task();


	//printing output
	printf("\n\n\nthe sorted order is :\n");
	for ( i = 0; i < len; ++i)
	{
		puts(a[i]);
	}
	return 0;
}