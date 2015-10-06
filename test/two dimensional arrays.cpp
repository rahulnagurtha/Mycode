#include <stdio.h>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
int main()
{
  int a[3][3]={1,2,3,4,5,6,7,8,9};
  int (*b)[3],*c;
  for(int i=0;i<3;i++)
  {
      b=a+i;
      c=(int *)b;
      for(int j=0;j<3;j++)
      {
         c=c+j;
         printf("%d\t",*c);
      }
  }
}
