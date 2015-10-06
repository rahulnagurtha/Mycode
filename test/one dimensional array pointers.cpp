#include <stdio.h>
#include <iostream>
#include <limits>
#include <string>
#include <new>
using namespace std;

template <class T>
T getmax(T a,T b)
{
  return (a>b?a:b);
}

int main()
{
  int i,j,k;
  i=9,j=10;
  cout << getmax(i,j);
}