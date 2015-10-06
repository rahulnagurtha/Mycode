#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
/*

The maximum number of inversions that an
n-size array can have is

    n*(n-1) / 2

*/
    using namespace std;

int count_inversion_merge(vector<int>array[], int first, int last)
{
    int mid = (first+last)/2;
    int ai = first;
    int bi = mid+1;
    int final[last-first+1], finali=0;
    int inversion = 0, i;

    while (ai <= mid && bi <= last) {
        if (array[ai] <= array[bi]) {
                final[finali++] = array[ai++];
        } else {
                final[finali++] = array[bi++];
                inversion += mid - ai + 1;
        }
    }

    while (ai <= mid)
        final[finali++] = array[ai++];

    while (bi <= last)
        final[finali++] = array[bi++];

    for (i=0 ; i<last-first+1 ; i++)
        array[i+first] = final[i];

    return inversion;
}

int count_inversion(vector<int> array[], int a, int b)
{
    int x, y, z, mid;
    if (a >= b) return 0;

    mid = (a+b)/2;

    x = count_inversion(array, a, mid);
    y = count_inversion(array, mid+1, b);
    z = count_inversion_merge(array, a, b);

    return x+y+z;
}

int main()
{
    int a[100009],i,j,k,l,m,n,inversion,len;
    scanf("%d%d",&len,&m);
    for (i = 0; i < len; ++i)
    {
    	scanf("%d",&a[i]);
    }
    for (i = 0; i < m; ++i)
    {
       scanf("%d%d",&j,&k);
       n=a[j-1];
       a[j-1]=a[k-1];
       a[k-1]=n;
       vector <int> b(a,a+len);
       inversion = count_inversion(b, 0, len-1);
       printf("%d\n", inversion%2);
       inversion=0;
    }
    return 0;
}
