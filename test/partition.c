#include <stdio.h>
#include <time.h>
int a[1111];
int len;
int rank,pivot=0;

int partition(int start,int end);

int main()
{
	clock_t t;
	int temp,i,j,k;
	printf("enter the size of the array: ");
	scanf("%d",&len);
	printf("enter the array:\n");
	for ( i = 0; i < len; ++i){
		scanf("%d",&a[i]);
	}
	rank=(len-1)/2;
	t = clock();
	partition(0,len-1);                // calling the recursive funtion
	printf("\n");
	for (i = 0; i < 1000; ++i){
		k++;
	}
	for (i = 0; i < len; ++i){
		printf("%d ",a[i]);
	}
	t = clock() - t;
	printf("\n\n\n");
	printf("the median of the given array is %d\n",a[pivot]);
	printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
	return 0;
}


int partition(int start,int end)
{
	int i,temp;
	pivot=start;
	for (i = start; i < end; ++i)
	{                                       //this funtion finds the index of a[end] in the sorted array without actually sorting the array
		if( a[i]<=a[end] )
		{
			temp=a[i];
			a[i]=a[pivot];
			a[pivot]=temp;
			pivot++;
		}
	}
	temp=a[end];
    a[end]=a[pivot];
    a[pivot]=temp;
    if(pivot==rank)
    {
        return a[pivot];
    }
    else if(pivot>rank)
    {
    	//printf("partition(%d,%d)\n",start,pivot-1);
    	partition(start,pivot-1);
    }
    else
    {
    	//printf("partition(%d,%d)\n",pivot+1,end);
    	partition(pivot+1,end);
    }
}






