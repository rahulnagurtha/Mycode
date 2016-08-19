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

#define LMT 1005
#define INF (1 << 30) 

int m,n;
int sum[3*LMT][3*LMT];
vector<pair<int,PII> > A;
deque<pair<int,PII> > Q;



int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) return 0;
    if (ly == tly && try_ == ry) {
        return sum[vx][vy];
    }
    int tmy = (tly + try_) / 2;
    int r1 = sum_y(vx, vy*2, tly, tmy, ly, min(ry,tmy));
    int r2 = sum_y(vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry);
    return r1 + r2;
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y (vx, 1, 1, m, ly, ry);
    int tmx = (tlx + trx) / 2;
    int r1 = sum_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry);
    int r2 = sum_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
    return r1 + r2;
}

void update_y (int vx, int lx, int rx, int vy, int ly, int ry, int xx, int yy, int val) {
    if (ly == ry) {
        if (lx == rx){
            sum[vx][vy] = val;
        }        
        else {
            sum[vx][vy] = sum[vx*2][vy] + sum[vx*2+1][vy];
        }
    }
    else {
        int my = (ly + ry) / 2;
        if(my >= yy) update_y(vx, lx, rx, vy*2, ly, my, xx, yy, val);
        else update_y(vx, lx, rx, vy*2+1, my+1, ry, xx, yy, val);
        sum[vx][vy] = sum[vx][vy *2] + sum[vx][vy *2 + 1];
    }
    return;
}

void update_x (int vx, int tlx, int trx, int xx,int yy,int val) {
    int tmx = (tlx + trx) / 2;
    if (tlx != trx) {
        if(tmx >= xx) update_x(vx*2, tlx, tmx, xx, yy,val);
        else update_x(vx*2+1, tmx+1, trx, xx, yy,val);
    }
    update_y(vx, tlx, trx, 1, 1, m, xx, yy, val);
    return;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    int tmp;
    int last = -1;
    ll ans = 0;
    si(n);
    m = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            si(tmp);
            A.pb(mp(tmp,mp(i,j)));
        }
    }
    sort(A.begin(),A.end());
    for (int i = 0; i < A.size(); ++i) {
        if(last != A[i].FF) {
            while(!Q.empty()) {
                update_x (1,1,n,Q.front().SS.FF,Q.front().SS.SS,1);
                Q.pop_front();
            }
        }
        ans = ans + sum_x(1,1,n,A[i].SS.FF,n,A[i].SS.SS,n);
        last = A[i].FF;
        Q.pb(A[i]);
    }
    plli(ans);
    return 0;
}