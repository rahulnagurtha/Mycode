#include <bits/stdc++.h>

using namespace std;



int main()
{
    int k,l,m,n,d,cnt = 0;
    scanf("%d %d %d %d %d",&k,&l,&m,&n,&d);
    for (int i = 1; i <= d; ++i)
    {
    	if(i%k == 0) {
    		cnt++;
    	}
    	else if(i%l == 0) {
    		cnt++;
    	}
    	else if(i%m == 0) {
    		cnt++;
    	}
    	else if(i%n == 0) {
    		cnt++;
    	}
    }
    printf("%d\n",cnt);
    return 0;
}