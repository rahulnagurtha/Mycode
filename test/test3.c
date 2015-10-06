#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int a[1000];
int len;

void swap_(int *num1,int *num2)
{
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
    return;
}

void heapify(int index,int s_len)
{
    int l,r,temp,largest;
    largest=index;
    while(1)
        {
            temp=largest;
            l=2*largest;
            r=2*largest+1;
            if((l<=s_len) && a[l] > a[largest]) largest=l;
            if((r<=s_len) && a[r] > a[largest]) largest=r;
            if(temp==largest) break;
            else 
                {
                    swap_(&a[largest],&a[temp]);
                    /*for (j = 1; j<=len ; ++j)
                    {
                        printf("%d ", a[j]);
                    }
                    printf("\n");*/
                }
        }
    return ;
}

void heap_sort()
{
    int i;
    for ( i = len; i >=2 ; --i)
    {
        swap_(&a[1],&a[i]);
        heapify(1,i-1);
    }
    return;
}



void build_heap(int index)
{
    int largest,temp,num,l,i,r,j;
    for ( i = index ; i >=1 ; --i) heapify(i,len);
    return;
}


int main()
{
    int temp,i,j,k;
    printf("number of elements in the array: ");
    scanf("%d",&len);
    printf("enter the elements:\n");
    for ( i = 1 ; i <= len ; ++i)
    {
        scanf("%d",&a[i]);
    }
    build_heap(len/2);
    for ( i = 1; i <=len ; ++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    heap_sort();
    printf("after sorting,the order is:\n");
    for ( i = 1; i <=len ; ++i)
    {
        printf("%d ",a[i]);
    }
}
