#include <bits/stdc++.h>

using namespace std;


#define si(i) 					scanf("%d",&i)
#define slli(i) 				scanf("%lld",&i)

#define pi(i) 					printf("%d\n",i)
#define plli(i) 				printf("%lld\n",i)

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			    ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			    (a-(box(a,b))*b)
#define ceil(a,b) 			    ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			    ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

VOLL info;
LL n,r,avg,one,two,answer,req,pre;


void solve() {
	req = avg*n;
	sort(info.begin(),info.end());
	for (int i = 0; i < n; ++i) {
		if(req <= pre) break;
		if( info[i].SS < r ) {
			pre += r - info[i].SS;
			answer += min((req - pre),(r - info[i].SS))*info[i].FF;
		}
	}
	plli(answer);
}



// main code begins now

int main()
{
    slli(n);slli(r);slli(avg);
    for (int i = 0; i < n; ++i) {
    	slli(one);slli(two);
    	pre += one;
    	info.pb(mp(one,two));
    }
    solve();
    return 0;
}