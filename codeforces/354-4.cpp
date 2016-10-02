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
int xT,yT,xM,yM;
int mask[1005][1005];
int Dis[4][1005][1005];
bool visited[4][1005][1005];
int curDis,curX,curY,curDir;

int dX[] = {-1,0,1,0};
int dY[] = {0,1,0,-1};

deque<pair<PII,int> > Q;

inline bool isIn(int xX,int yY) {
    return (xX >= 1 && xX <=n && yY >= 1 && yY <= m);
}

inline bool isOpen(int msk,int num) {
    return ( (msk >> (4 - num)) & 1); 
}


int main()
{
    SYNC;
    int me,nextguy;
    string tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        for (int j = 1; j <= m; ++j) {
            if(tmp[j-1] == '+') mask[i][j] = 15;
            else if(tmp[j-1] == '-') mask[i][j] = 5;
            else if(tmp[j-1] == '|') mask[i][j] = 10;
            else if(tmp[j-1] == '^') mask[i][j] = 8;
            else if(tmp[j-1] == '>') mask[i][j] = 4;
            else if(tmp[j-1] == '<') mask[i][j] = 1;
            else if(tmp[j-1] == 'v') mask[i][j] = 2;
            else if(tmp[j-1] == 'L') mask[i][j] = 14;
            else if(tmp[j-1] == 'R') mask[i][j] = 11;
            else if(tmp[j-1] == 'U') mask[i][j] = 7;
            else if(tmp[j-1] == 'D') mask[i][j] = 13;
            else if(tmp[j-1] == '*') mask[i][j] = 0;
        }
    }
    cin >> xT >> yT >> xM >> yM;
    visited[0][xT][yT] = true;
    Q.pb(mp(mp(xT,yT),0));
    Dis[0][xT][yT] = 0;

    while(!Q.empty()) {
        curX = Q.front().FF.FF;
        curY = Q.front().FF.SS;
        curDir = Q.front().SS;
        curDis = Dis[curDir][curX][curY];
        Q.pop_front();
        me = ((mask[curX][curY] >> curDir) | (mask[curX][curY] << (4-curDir)));
        if (curX == xM && curY == yM) {
            cout << curDis << endl;
            return 0;
        }
        if (!visited[(curDir+1)&3][curX][curY]) {
            visited[(curDir+1)&3][curX][curY] = true;
            Dis[(curDir+1)&3][curX][curY] = curDis + 1;
            Q.pb(mp(mp(curX,curY),(curDir+1)&3));
        }
        for (int i = 0; i < 4; ++i) {
            if(!isIn(curX+dX[i],curY+dY[i])) continue;
            if(visited[curDir][curX+dX[i]][curY+dY[i]]) continue;

            nextguy = ((mask[curX+dX[i]][curY+dY[i]] >> curDir) | (mask[curX+dX[i]][curY+dY[i]] << (4-curDir)));
            if(i == 0) {
                if( !(isOpen(me,1)) || !(isOpen(nextguy,3))) continue;
            }
            if(i == 1) {
                if( !(isOpen(me,2)) || !(isOpen(nextguy,4))) continue;
            }
            if(i == 2) {
                if( !(isOpen(me,3)) || !(isOpen(nextguy,1))) continue;
            }
            if(i == 3) {
                if( !(isOpen(me,4)) || !(isOpen(nextguy,2))) continue;
            }
            visited[curDir][curX+dX[i]][curY+dY[i]] = true;
            Q.pb(mp(mp(curX+dX[i],curY+dY[i]),curDir));
            Dis[curDir][curX+dX[i]][curY+dY[i]] = curDis + 1;
        }
    }
    cout << "-1" << endl;
    return 0;
}
