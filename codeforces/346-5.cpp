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
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

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


int n,m;
VOII edges;
int one,two;
VOVI graph(100005);
int compedges[100005] = {0};
int compver[100005] = {0};
int component[100005] = {0};
bool visited[100005] = {false};


void dfs(int pre,int num) {
    visited[pre] = true;
    compver[num]++;
    component[pre] = num;
    for (int i = 0; i < graph[pre].size(); ++i) {
        if(!visited[graph[pre][i]]) dfs(graph[pre][i],num);
    }
    return;
}

int main()
{
    int cur = 1;
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> one >> two;
        edges.pb(mp(one,two));
        graph[one].pb(two);
        graph[two].pb(one);
    }
    for (int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            dfs(i,cur);
            cur++;
        }
    }
    for (int i = 0; i < edges.size(); ++i) {
        compedges[component[edges[i].FF]]++;
    }
    for (int i = 1; i <= 100005; ++i) {
        if (compver[i] == 0) {
            break;
        }
        if (compedges[i] < compver[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
