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

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define Ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


struct node {
	int l,r,num;
}query[100005];

int n,m,a[100005],ans[100005],cnt[100005],bsize,curans,curL,curR;


bool cmp(struct node one,struct node two) {
	if(Ceil(one.l,bsize) == Ceil (two.l,bsize)) return one.r < two.r;
	return Ceil(one.l,bsize) < Ceil (two.l,bsize);
}


void init() {
	curans = 0;
	curL = 1;
	curR = 1;
	if(a[1] <= n) {
		cnt[a[1]]++;
		if(cnt[a[1]] == a[1]) curans++;
	}
	sort(query,query + m,cmp);
	return;
}

inline void add(int cur) {
	if(a[cur] > n) return;
	if(cnt[a[cur]] == a[cur]) curans--;
	cnt[a[cur]]++;
	if(cnt[a[cur]] == a[cur]) curans++;
	return;
}

inline void remove(int cur) {
	if(a[cur] > n) return;
	if(cnt[a[cur]] == a[cur]) curans--;
	cnt[a[cur]]--;
	if(cnt[a[cur]] == a[cur]) curans++;
	return;
}

int main()
{
    si2(n,m);
    bsize = ceil(sqrt(m));
    for (int i = 1; i <= n; ++i) {
    	si(a[i]);
    }
    for (int i = 0; i < m; ++i) {
    	si2(query[i].l,query[i].r);
    	query[i].num = i;
    }
    init();
	for (int i = 0; i < m; ++i) {
		while(curL > query[i].l) {
			curL--;
			add(curL);
		}
		while(curR < query[i].r) {
			curR++;
			add(curR);
		}
		while(curL < query[i].l) {
			remove(curL);
			curL++;
		}
		while(curR > query[i].r) {
			remove(curR);
			curR--;
		}
		ans[query[i].num] = curans;
	}
	for (int i = 0; i < m; ++i) {
		pi(ans[i]);
	}
    return 0;
}