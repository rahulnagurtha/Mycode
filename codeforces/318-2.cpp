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
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


VOLL edges;
LL n,m;
LL cnt[4005];
LL anssofar,temp,one,two;
bool matrix[4005][4005];


// main code begins now

int main()
{
	slli2(n,m);
	fill(cnt,0);
	fill(matrix,false);
	anssofar = (LL)(INT_MAX);
	for (int i = 0; i < m; ++i) {
		slli2(one,two);
		cnt[one]++;
		cnt[two]++;
		matrix[one][two] = true;
		matrix[two][one] = true;
		edges.pb(mp(one,two));
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(matrix[edges[i].FF][j] && matrix[edges[i].SS][j]) {
				if(cnt[edges[i].FF] + cnt[edges[i].SS] + cnt[j] - 6 < anssofar) anssofar = cnt[edges[i].FF] + cnt[edges[i].SS] + cnt[j] - 6;
			}
		}
	}
	if(anssofar == (LL)(INT_MAX)) printf("-1\n");
	else plli(anssofar);
    return 0;
}