#include <stdio.h>
#include <iostream>
#include <limits>
#include <string>
#include <new>
using namespace std;

template <class T,class t,class r>
T getmax(T a,t b,T c,r d)
{
    cout << d <<endl;
  cout << b << endl ;
  return (a>b?a:b);
}

int main()
{
  int i,j,k;
  i=9,j=10;
  float p=8.9;
  double q=1000000000000;
  cout << getmax(i,p,j,q);
}
