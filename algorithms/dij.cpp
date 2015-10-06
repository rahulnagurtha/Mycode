        
#ifndef ONLINE_JUDGE
#   define DEBUG
#   define TRACE
#else
#   define NDEBUG
#endif




#include <bits/stdc++.h>

using namespace std;




#ifdef DEBUG
     #define debug(args...)            {cerr<<__FUNCTION__<<":"<<__LINE__<<":";dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;



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
#define rem1(a,b)               ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007
#define INF                     2000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;



// main code begins now

int main()
{
    int E,V,u,v,w,s,t;
    vector<vector<PII> > graph(100005);
    priority_queue<PII, VOII, greater<PII> > Q;
    PII tmp;
    VI dist(100005,INF),parent(100005,-1);
    si2(E,V);
    for (int i = 0; i < E; ++i) {
        si3(u,v,w);
        graph[u].pb(mp(v,w));
    }
    si2(s,t);
    Q.push(mp(0,s));
    dist[s] = 0;
    while(!Q.empty()) {
        tmp = Q.top();
        debug(tmp.SS,tmp.FF);
        Q.pop();
        if( tmp.SS == t || tmp.FF == INF) break;
        for (int i = 0; i < graph[tmp.SS].size(); ++i) {
            if(dist[tmp.SS] + graph[tmp.SS][i].SS < dist[graph[tmp.SS][i].FF]) {
                dist[graph[tmp.SS][i].FF] = dist[tmp.SS] + graph[tmp.SS][i].SS;
                parent[graph[tmp.SS][i].FF] = tmp.SS;
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