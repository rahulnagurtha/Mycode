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

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;



int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
        int m,n,in,out,weight,a,b,dist[10005];
        vector<VOII> graph(10005);
        bool explored[10005];
        priority_queue<PII, VOII, greater<PII> > Q;
        PII temp;
        for (int i = 0; i < 10005; ++i) dist[i] = INT_MAX;
        fill(explored,false);
        si2(n,m);
        for (int i = 0; i < m; ++i) {
            si3(out,in,weight);
            graph[out].pb(mp(in,weight));
        }
        si2(a,b);
        Q.push(mp(0,a));
        dist[a] = 0;
        while(!Q.empty()) {
            temp = Q.top();
            Q.pop();
            if(explored[temp.SS]) continue;
            if(temp.SS == b) break;
            explored[temp.SS] = true;
            for (int i = 0; i < graph[temp.SS].size(); ++i) {
                if(dist[temp.SS] + graph[temp.SS][i].SS < dist[graph[temp.SS][i].FF]) {
                    dist[graph[temp.SS][i].FF] = dist[temp.SS] + graph[temp.SS][i].SS;
                    Q.push(mp(dist[graph[temp.SS][i].FF],graph[temp.SS][i].FF));
                }
            }
        }
        if(dist[b] == INT_MAX) printf("NO\n");
        else printf("%d\n",dist[b]);
    }
    return 0;
}