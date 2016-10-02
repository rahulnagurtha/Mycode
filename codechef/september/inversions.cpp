#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;


// fast input

#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
int readint()
{
register char c=gc();
while(c<'0'||c>'9')
    c=gc();  //ignore all characters till the first digit
int ret=0;
while(c>='0' && c<='9') //till we get a stream of digits.As soon as we get something else,we stop
{
ret=ret*10+(c-48);//construct the number
c=gc();
}
return ret;
}



long long int  _mergeSort(int arr[], int temp[], int left, int right);
long long int merge(int arr[], int temp[], int left, int mid, int right);
  
/* This function sorts the input array and returns the
   number of inversions in the array */
long long int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
  
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
long long int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid;
  long long inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
  
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
  
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
  
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
long long int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  long long int inv_count = 0;
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
  
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }
  
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];
  
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  
  return inv_count;
}
  
/* Driver progra to test above functions */
int main()
{
    int a[200005],b[200005];
    int n,m;
    long long int inv,temp;
    cin >> n >> m ;
    for (int i = 0; i < n; ++i)
    {
      a[i]=readint();
      b[i]=a[i];
    }
    inv=mergeSort(a, n);
    temp=inv;
    int count,one,two,three,four;
    //printf("Number of inversions are %lld \n",inv);
    //getchar();
    for (int i = 0; i < m; ++i)
    {
      temp=inv;
      one=readint();
      two=readint();
      three=min(one,two);
      four=max(one,two);
      //printf("%d %d\n",three,four);
      for (int j = three; j <= four-1; ++j)
      {
        if (b[j]>b[three-1]) {
          temp++;
          //printf("%d>%d      %lld\n",b[j],b[three-1],temp);
          //temp++;
        }
        if (b[j]<b[three-1]){
          temp--;
         //printf("%d<%d       %lld\n",b[j],b[three-1],temp);
         
        }
      }
      for (int j = four-2; j >= three; --j)
      {
        if (b[j]<b[four-1]){
          temp++;
         //printf("%d<%d     %lld\n",b[j],b[four-1],temp);
         
        }
        if (b[j]>b[four-1]){
          temp--;
         //printf("%d>%d     %lld\n",b[j],b[four-1],temp);
         
        }
      }
      printf("%lld\n",temp);
    }
    return 0;
}