#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int a[15],temp;
        for (int i = 0; i < 14; ++i)
        {
            scanf("%d",&a[i]);
        }
        for (int i = 0; i < 13; ++i)
        {
            for (int j = 0; j < 13-i; ++j)
            {
                if(a[j+1]<a[j])
                {
                    temp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                }
            }
        }
        printf("\nthe sorted array is:\n");
        for (int i = 0; i < 14; ++i)
        {
            printf("%d ", a[i]);
        }

    }
    return 0;
}






