#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n,tym[100005],temp,answer;

// main code begins now

int main()
{
    scanf("%I64d",&n);
    for (int i = 1; i <= n; ++i) {
    	scanf("%I64d",&tym[i]);
    }
    sort(tym+1,tym+n+1);
    temp = tym[1];
    answer = 1;
    for (int i = 2; i <= n; ++i) {
    	if(tym[i] >= temp) {
    		answer++;
    		temp += tym[i];
    	}
    }
    printf("%I64d\n",answer);
    return 0;
}