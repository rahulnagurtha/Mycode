#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int readint()
{
    int cc = getc(stdin);
    for (;cc < '0' || cc > '9';)
            cc = getc(stdin);
    int ret = 0;
    for (;cc >= '0' && cc <= '9';)
    {
            ret = ret * 10 + cc - '0';
            cc = getc(stdin);
    }
    return ret;
}


int main()
{
    int a,b;
    a=readint();
    b=readint();
    printf("%d %d",a,b);
    return 0;
}


abra
