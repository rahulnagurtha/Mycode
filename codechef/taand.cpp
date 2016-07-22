#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


int n;
VS bitValues;
int A[3*100005];
int tmp,maxBits;

string DecToBin(int number){
    string result = "";
    do {
        if((number&1)==0)
            result+="0";
        else
            result+="1";
        number>>=1;
    }while(number);
    while(result.size() < maxBits) {
    	result += '0';
    }
    reverse(result.begin(),result.end());
    return result;
}

inline int numBitsSet(int key) {
	int ret = 0;
	while(key > 0) {
		ret += key%2;
		key /= 2;
	}
	return ret;
}

int main()
{
	ll ans = 0;
    si(n);
    maxBits = 0;
    for (int i = 0; i < n; ++i) {
    	si(A[i]);
    	maxBits = max(maxBits,numBitsSet(A[i]));
    }
    for (int i = 0; i < n; ++i) {
    	bitValues.pb(DecToBin(A[i]));
    }
    sort(bitValues.begin(),bitValues.end());
    string one = bitValues[bitValues.size()-1],two = bitValues[bitValues.size()-2];
    ll tmp = 1;
    for (int i = one.size() - 1; i >= 0; --i) {
    	if((one[i] == '1') && (two[i] == '1')) ans += tmp;
    	tmp = tmp*2;
    }
    plli(ans);
    return 0;
}