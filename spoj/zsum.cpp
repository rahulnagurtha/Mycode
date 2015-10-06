#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
#define MOD 10000007

LL fast_exp(LL base,LL expo) {
    LL res=1;
    while(expo>0) {
       if(expo%2==1) res=(res*base) % MOD;
       base=(base*base) % MOD;
       expo/=2;
    }
    return res % MOD;
}


// main code begins now

int main()
{
    LL t,answer,n,k;
    // freopen("in.txt", "r", stdin);
    while(1) {
    	answer = 0;
    	cin >> n >> k;
        if(n == 0 && k == 0) break;
    	answer += fast_exp(n,k);
    	answer %= MOD ;
    	answer += 2*fast_exp(n-1,k);
    	answer %= MOD ;
    	answer += fast_exp(n,n);
    	answer %= MOD ;
    	answer += 2*fast_exp(n-1,n-1);
    	answer %= MOD ;
    	cout << answer << endl;
    }
    return 0;
}