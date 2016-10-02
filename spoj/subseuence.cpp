#include<stdio.h>
int main()
{
    unsigned long long int t;
    scanf("%llu",&t);
    while(t--)
    {
              unsigned long long int tm=0,n,m,k,i;
              scanf("%llu %llu %llu",&n,&k,&m);
              m=m/n;
              for(i=n;i<=m;i=i*k)
              {
                             tm=tm+1;
              }
              printf("%llu\n",tm);
    }
    return 0;
}
    


