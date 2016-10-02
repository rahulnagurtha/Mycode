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
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL
#define INF                     2000000007

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


PII tmp;
int E,V,u,v,w,s,t;
bool explored[100005];
vector<vector<PII> > graph(100005);
VI dist(100005,INF),parent(100005,-1);
priority_queue<PII, VOII, greater<PII> > Q;


void init() {
    fill(explored,false);
    dist[s] = 0;
    Q.push(mp(0,s));
    explored[s] = true;
    return;
}


int main()
{
    si2(E,V);
    for (int i = 0; i < E; ++i) {
        si3(u,v,w);
        graph[u].pb(mp(v,w));
    }
    si2(s,t);
    init();
    while(!Q.empty()) {
        tmp = Q.top();
        cout << tmp.SS << tmp.FF << endl;
        Q.pop();
        if( tmp.SS == t || tmp.FF == INF) break;
        if(explored[tmp.SS]) continue;
        explored[tmp.SS] = true;
        for (int i = 0; i < graph[tmp.SS].size(); ++i) {
            if(dist[tmp.SS] + graph[tmp.SS][i].SS < dist[graph[tmp.SS][i].FF]) {
                parent[graph[tmp.SS][i].FF] = tmp.SS;
                dist[graph[tmp.SS][i].FF] = dist[tmp.SS] + graph[tmp.SS][i].SS;
                Q.push(mp(dist[graph[tmp.SS][i].FF],graph[tmp.SS][i].FF));
            }
        }
    }
    if(dist[t] == INF) {
        printf("NO\n");
        return 0;
    }
    printf("%d\n",dist[t]);
    for (int i = t; i != s ; i = parent[i]) {
        printf("%d ",parent[i]);
    }
    printf("\n");
    return 0;
}