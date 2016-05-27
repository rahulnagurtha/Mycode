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
bool visited[4][1005][1005];
deque<pair<PII,int> > Q;
int mask[1005][1005];
int xT,yT,xM,yM;
int curD,curX,curY;

bool isIn(int xX,int yY) {
    return (xX >= 1 && xX <=n && yY >= 1 && yY <= m);
}


int main()
{
    SYNC;
    pair<PII,int> curPt;
    string tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        for (int j = 1; j <= m; ++j) {
            if(tmp[j] == '+') mask[i][j] = 15;
            else if(tmp[j] == '-') mask[i][j] = 5;
            else if(tmp[j] == '|') mask[i][j] = 10;
            else if(tmp[j] == '^') mask[i][j] = 8;
            else if(tmp[j] == '>') mask[i][j] = 4;
            else if(tmp[j] == '<') mask[i][j] = 1;
            else if(tmp[j] == 'v') mask[i][j] = 2;
            else if(tmp[j] == 'L') mask[i][j] = 14;
            else if(tmp[j] == 'R') mask[i][j] = 13;
            else if(tmp[j] == 'U') mask[i][j] = 7;
            else if(tmp[j] == 'D') mask[i][j] = 11;
            else if(tmp[j] == '*') mask[i][j] = 0;
        }
        cin >> xT >> yT >> xM >> yM;
        visited[xT][yT] = true;
        Q.pb(mp(mp(xT,yT),0));
        while(!Q.empty()) {

        }
    return 0;
}
