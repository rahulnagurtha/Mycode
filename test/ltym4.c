#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int a[30],mycount=0;
char array[10];
int i,n,r;
char output[27];

// main code begins now

void permute()
{
    int temp,i,j,len;
    temp=strlen(output);
    if(temp==r) 
    {
        //printing out the string
        mycount++;
        strlen(output);
        printf("%d--->%s\n",mycount,output);
        //printf("%s\n",output);
        //exit(0);
    }
    else
    {
        for (i = 0; i < n ;i++)
        {
            if(a[i]!=1)   //checking whether the element is already in the string
            {
                a[i]=1;
                len = strlen(output);
                output[len]=array[i];
                //calling the same function again on the reemaining elements
                permute();
                a[i]=0;
                //I am erasing output[len]
                output[len]='\0';
            }
        }
    }
}


int main()
{
    int i,j,k;
    for ( i = 0; i < 27; ++i)
    {
        output[i]='\0';
    }
    for ( i = 0; i <=26; ++i) 
    {
        a[i]=0;
    }
    printf("no. of characters: ");
    scanf("%d",&n);
    printf("enter the value of r: ");
    scanf("%d",&r);
    getchar();
    printf("enter the characters:\n");
    for (i = 0; i < n ; ++i) 
    {
        scanf("%c",&array[i]);
        getchar();
    }
    for ( i = 0; i < n; ++i)
    {
        printf("%c ",array[i] );
    }
    printf("\n");
    permute();
    return 0;
}