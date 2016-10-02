#include <bits/stdc++.h>

using namespace std;


#define si(i) 					scanf("%d",&i)
#define slli(i) 				scanf("%I64d",&i)

#define pi(i) 					printf("%d\n",i)
#define plli(i) 				printf("%I64d\n",i)

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
	answer = 0;
	sort(info.begin(),info.end());
	for (int i = 0; i < n; ++i) {
		if(req <= pre) break;
		if( info[i].SS < r ) {
			answer += (LL)(min(req-pre,r - info[i].SS))*info[i].FF;
			pre += r - info[i].SS;
		}
	}
	plli(answer);
}



// main code begins now

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	pre = 0;
    slli(n);slli(r);slli(avg);
    for (int i = 0; i < n; ++i) {
    	slli(one);slli(two);
    	pre += one;
    	info.pb(mp(two,one));
    }
    solve();
    return 0;
}