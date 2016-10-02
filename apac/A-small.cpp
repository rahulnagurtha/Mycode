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


double answer;
double P,Q;

string Grid[25][25];
int visited[25][25];
int r,c;

bool isInside(int x,int y) {
    return (0 <= x && x < r && 0 <= y && y < c);
}

inline void Refresh() {
    answer = 0;
    fill(visited,0);
}


void dfs(int remSteps,double curSum,int x,int y) {
    // cout << remSteps << " " << curSum << " " << x << " " << y << endl;
    if(remSteps == 0) {
        answer = max(answer,curSum);
        return;
    }
    visited[x][y]++;
    for (int i = 0; i < 4; ++i) {
        if(isInside(x + dX[i],y+dY[i])) {
            int nx = x + dX[i];
            int ny = y + dY[i];
            if(Grid[nx][ny] == ".") {
                double tmp = 1;
                for (int j = 0; j < visited[nx][ny]; ++j) {
                    tmp = tmp*(1 - Q);
                }
                dfs(remSteps - 1,curSum + tmp*Q, nx, ny);
            }
            else {
                double tmp = 1;
                for (int j = 0; j < visited[nx][ny]; ++j) {
                    tmp = tmp*(1 - P);
                }
                dfs(remSteps - 1,curSum + tmp*P, nx, ny);
            }
        }
    }
    visited[x][y]--;
    return;
}

int main()
{
    int t;
    int testcase = 1;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
        Refresh();
        int rs,cs;
        int s;
        cout << "Case #" << testcase << ": ";
        cin >> r >> c >> rs >> cs >> s;
        cin >> P >> Q;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> Grid[i][j];
            }
        }
        dfs(s,0,rs,cs);
        cout.precision(10);
        cout << fixed << answer << endl;
        testcase++;
    }
    return 0;
}