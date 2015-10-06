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


int n,m,k,in,out,T,X,cur,timestamp,X1,X2;
deque<PII> Q;
map<PII,int> deleted;
map<PII,int>::iterator it;
PII one;
bool visited[100005];
VOVI graph(100005);
VOII edges;


int main()
{
	fill(visited,false);
    si3(n,m,k);
    for (int i = 0; i < m; ++i) {
    	si2(in,out);
    	graph[in].pb(out);
    	graph[out].pb(in);
    	if(in > out) edges.pb(mp(in,out));
    	else edges.pb(mp(out,in));
    }
    for (int i = 0; i < k; ++i) {
    	si2(T,X);
    	deleted[edges[X-1]] = T;
    }
    Q.pb(mp(1,0));
    visited[1] = true;
    while(!Q.empty()) {
    	one = Q.front();
    	Q.pop_front();
    	timestamp = one.SS;
    	cur = one.FF;
    	if(cur == n) {
    		pi(timestamp);
    		return 0;
    	}
    	for (int i = 0; i < graph[cur].size(); ++i) {
    		X1 = max(cur,graph[cur][i]);
    		X2 = min(cur,graph[cur][i]);	
    		it = deleted.find(mp(X1,X2));
    		if( ( it != deleted.end() ) && (it->SS <= timestamp) ) continue;
			if(!visited[graph[cur][i]]) {
				Q.push_back(mp(graph[cur][i],timestamp+1));
				visited[graph[cur][i]] = true;
			}
    	}
    }
    printf("-1\n");
    return 0;
}