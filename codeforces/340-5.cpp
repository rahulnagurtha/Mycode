#include <bits/stdc++.h>

using namespace std;

#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define Ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                (((a)<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int pre[100005],n,m,k;
int cnt[2000005],l,r;
ll ans;
ll qans[100005];
vector<pair<PII,PII> > queries;
int bsize;


bool cmp(pair<PII,PII> one,pair<PII,PII> two) {
	if(one.SS.FF != two.SS.FF) return one.SS.FF < two.SS.FF;
	else return one.FF.SS < two.FF.SS;
}

void add(int cur) {
	ans += cnt[k^pre[cur]];
	cnt[pre[cur]]++;
	return;
}

void remove(int cur) {
	cnt[pre[cur]]--;
	ans -= cnt[k^pre[cur]];
	return;
}


void init() {
	add(0);
	add(1);
	l = 0;
	r = 1;
	return;
}

int main()
{
	int one,two,curl,curr;
    si3(n,m,k);
    pre[0] = 0;
    bsize = ceil(sqrt(n));
    for(int i = 1; i <= n; ++i) {
    	si(one);
    	pre[i] = (pre[i-1] ^ one);
    }
    for(int i = 0; i < m; ++i) {
    	si2(one,two);
    	one--;
    	queries.pb(mp(mp(one,two),mp(Ceil(one+1,bsize),i)));
    }
    sort(queries.begin(),queries.end(),cmp);
    init();
    for(int i = 0; i < m; ++i) {
    	curl = queries[i].FF.FF;
    	curr = queries[i].FF.SS;
    	while(curl < l) {
    		l--;
    		add(l);
    	}
    	while(curr > r) {
    		r++;
    		add(r);
    	}
    	while(curl > l) {
    		remove(l);
    		l++;
    	}
    	while(curr < r) {
    		remove(r);
    		r--;
    	}
    	qans[(queries[i]).SS.SS] = ans;
    }
    for(int i = 0; i < m; ++i) plli(qans[i]);
    return 0;
}