#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                       100007


typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};


//graphs
VI dGraph[N];
VI uGraph[N];
VI rDGraph[N];
VI brandNewGraph[N];

//undirected details
int uCompnum[N];
int totalUComponents;

//directed component details
int dCompNum[N];
ll dCompMax[N];
ll dCompMin[N];
int totaldComponents;


//SCC component details
stack<int> T;
int regionHead[N];

ll answer;
ll height[N];
bool visited[N];
VL sccVertices[N];
ll maxUnderThis[N];


//split into undirected components
void dfs_pass_one(int cur,int idx) {
    visited[cur] = true;
    uCompnum[cur] = idx;
    for (int i = 0; i < uGraph[cur].size(); ++i) {
        if(!visited[uGraph[cur][i]]) dfs_pass_one(uGraph[cur][i],idx);
    }
    return;
}


//get rough estimate of toposort order of directed components
void dfs_pass_two(int cur) {
    visited[cur] = true;
    for (int i = 0; i < dGraph[cur].size(); ++i) {
        if(!visited[dGraph[cur][i]]) dfs_pass_two(dGraph[cur][i]);
    }
    T.push(cur);
    return;
}


//number the vertices in the order of toposort directed components
void dfs_pass_three(int cur,int idx) {
    visited[cur] = true;
    dCompNum[cur] = idx;
    for (int i = 0; i < rDGraph[cur].size(); ++i) {
        if(!visited[rDGraph[cur][i]]) dfs_pass_three(rDGraph[cur][i],idx);
    }
    return;
}


//the max under this subtree
ll dfs_pass_four(int cur) {
    if(maxUnderThis[cur] != -1) return maxUnderThis[cur];

    ll retVal = dCompMax[cur];
    ll curmaxsofar = INT_MIN;
    for (int i = 0; i < brandNewGraph[cur].size(); ++i) {
        int ver = brandNewGraph[cur][i];
        for (int j = 0; j < dGraph[ver].size(); ++j) {
            if(dCompNum[dGraph[ver][j]] == cur) continue;
            if(maxUnderThis[dCompNum[dGraph[ver][j]]] == -1) dfs_pass_four(dCompNum[dGraph[ver][j]]);
            curmaxsofar = max(curmaxsofar,maxUnderThis[dCompNum[dGraph[ver][j]]]);
        }
    }
    if(curmaxsofar != INT_MIN) {
        retVal = max(retVal,curmaxsofar);
        answer = max(answer,curmaxsofar - dCompMin[cur]);
    }
    maxUnderThis[cur] = retVal;
    return retVal;
}

void inline Refresh() {
    answer = INT_MIN;
    totalUComponents = 0;
    totaldComponents = 0;
    fill(maxUnderThis,-1);
    fill(uCompnum,-1);
    fill(dCompNum,-1);
    fill(dCompMin,-1);
    fill(dCompMax,-1);
    for (int i = 0; i < N; ++i) {
        dGraph[i].clear();
        uGraph[i].clear();
        rDGraph[i].clear();
        sccVertices[i].clear();
        brandNewGraph[i].clear();
    }
    return;
}



int main()
{
    int t;
    si(t);
    while(t--) {
        Refresh();
        int n,m;
        int a,b;
        si2(n,m);
        for (int i = 1; i <= n; ++i) {
            slli(height[i]);
        }
        for (int i = 0; i < m; ++i) {
            si2(a,b);
            dGraph[a].pb(b);
            rDGraph[b].pb(a);
            uGraph[a].pb(b);
            uGraph[b].pb(a);
        }

        //form undirected components
        fill(visited,false);
        for (int i = 1; i <= n; ++i) {
            if(!visited[i]) {
                totalUComponents++;
                dfs_pass_one(i,totalUComponents);
            }
        }
        //form directed components
            //step-1:preprocess
        fill(visited,false);
        for (int i = 1; i <= n; ++i) {
            if(!visited[i]) {
                dfs_pass_two(i);
            }
        }
            //step-2:calculate
        fill(visited,false);
        while(!T.empty()) {
            if(!visited[T.top()]) {
                totaldComponents++;
                dfs_pass_three(T.top(),totaldComponents);
            }
            T.pop();
        }

        //process
        for (int i = 1; i <= n; ++i) {
            brandNewGraph[dCompNum[i]].pb(i);
            sccVertices[dCompNum[i]].pb(height[i]);
        }
        for (int i = 1; i <= totaldComponents; ++i) {
            sort(sccVertices[i].begin(),sccVertices[i].end());
            dCompMax[i] = sccVertices[i].back();
            dCompMin[i] = sccVertices[i][0];
            if (sccVertices[i].size() > 1) {
                answer = max(answer,sccVertices[i].back() - sccVertices[i][0]);
            }
        }
        //process each component
        for (int i = 1; i <= n; ++i) {
            dfs_pass_four(dCompNum[i]);
        }
        //output the answer
        plli(answer);
    }
    return 0;
}