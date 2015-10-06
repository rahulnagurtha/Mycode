#include <stdio.h>
int main()
{
    int a[100009],count=0,len,inversion,i,j,k,l,b,c;
    scanf("%d%d",&len,&k);
    for ( i = 0; i < len; ++i)
    {
        scanf("%d",&a[i]);
    }
    for ( l = 0; l < k; ++l)
    {
        scanf("%d%d",&b,&c);
        l=a[b-1];
        a[b-1]=a[c-1];
        a[c-1]=l;
        for(i=0;i<len-1;i++)
        {
           for(j=i+1;j<len;j++)
           {
            if(a[i]>a[j])
            count++;
           }
        }
        count=count%2;
        printf("%d\n",count);
        count=0;
    }
    return 0;
}
