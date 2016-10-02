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

int m,n;
int sum[4*LMT][4*LMT];
int mini[4*LMT][4*LMT];
int maxi[4*LMT][4*LMT];
int a[LMT][LMT];


////////////remember that the dimensions must be made global i.e m,n should be global
inline void calculate(int vx,int vy,int parity) {
    if(parity == 0) {
        mini[vx][vy] = max(mini[vx << 1][vy] , mini[(vx << 1) + 1][vy] );
        maxi[vx][vy] = min(maxi[vx << 1][vy] , maxi[(vx << 1) + 1][vy] );
        sum[vx][vy] = sum[vx << 1][vy] + sum[(vx << 1) + 1][vy];
    }
    else {
        mini[vx][vy] = max(mini[vx][vy << 1] , mini[vx][(vy << 1) + 1]);
        maxi[vx][vy] = min(maxi[vx][vy << 1] , maxi[vx][(vy << 1) + 1]);
        sum[vx][vy] = sum[vx][vy << 1] + sum[vx][1 + (vy << 1)];
    }
}

void build_y (int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx) {
            mini[vx][vy] = a[lx][ly];
            maxi[vx][vy] = a[lx][ly];
            sum[vx][vy] = a[lx][ly];
        }   
        else calculate(vx,vy,0);
    }
    else {
        int my = (ly + ry) >> 1;
        build_y (vx, lx, rx, (vy << 1), ly, my);
        build_y (vx, lx, rx, (vy << 1)+1, my+1, ry);
        calculate(vx,vy,1);
    }
}
 
void build_x (int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) >> 1;
        build_x ((vx << 1), lx, mx);
        build_x ((vx << 1)+1, mx+1, rx);
    }
    build_y (vx, lx, rx, 1, 1, m);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int xx, int yy, int val) {
    if (ly == ry) {
        if (lx == rx){
            mini[vx][vy] = val;
            maxi[vx][vy] = val;
            sum[vx][vy] = val;
        }        
        else {
            calculate(vx,vy,0);
        }
    }
    else {
        int my = (ly + ry) >> 1;
        if(my >= yy) update_y(vx, lx, rx, vy << 1, ly, my, xx, yy, val);
        else update_y(vx, lx, rx, (vy << 1)+1, my+1, ry, xx, yy, val);
        calculate(vx,vy,1);
    }
    return;
}

void update_x(int vx, int tlx, int trx, int xx,int yy,int val) {
    if (tlx != trx) {
        int tmx = (tlx + trx) >> 1;
        if(tmx >= xx) update_x((vx << 1), tlx, tmx, xx, yy,val);
        else update_x((vx << 1)+1, tmx+1, trx, xx, yy,val);
    }
    update_y(vx, tlx, trx, 1, 1, m, xx, yy, val);
    return;
}

int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) return 0;
    if (ly == tly && try_ == ry) {
        return sum[vx][vy];
    }
    int tmy = (tly + try_) >> 1;
    int r1 = sum_y(vx, vy << 1, tly, tmy, ly, min(ry,tmy));
    int r2 = sum_y(vx, (vy << 1)+1, tmy+1, try_, max(ly,tmy+1), ry);
    return r1 + r2;
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y (vx, 1, 1, m, ly, ry);
    int tmx = (tlx + trx) >> 1;
    int r1 = sum_x (vx << 1, tlx, tmx, lx, min(rx,tmx), ly, ry);
    int r2 = sum_x ((vx << 1)+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
    return r1 + r2;
}

int max_y (int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) return -1;
    if (ly == tly && try_ == ry) return maxi[vx][vy];
    int tmy = (tly + try_) / 2;
    int r1 = max_y (vx, vy*2, tly, tmy, ly, min(ry,tmy));
    int r2 = max_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry);
    return max(r1,r2);
}
 
int max_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return -1;
    if (lx == tlx && trx == rx)
        return max_y (vx, 1, 1, m, ly, ry);
    int tmx = (tlx + trx) / 2;
    int r1 = max_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry);
    int r2 = max_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
    return max(r1,r2);
}

int min_y (int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) return INT_MAX;
    if (ly == tly && try_ == ry) return maxi[vx][vy];
    int tmy = (tly + try_) / 2;
    int r1 = min_y (vx, vy*2, tly, tmy, ly, min(ry,tmy));
    int r2 = min_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry);
    return max(r1,r2);
}

int min_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return INT_MAX;
    if (lx == tlx && trx == rx)
        return min_y (vx, 1, 1, m, ly, ry);
    int tmx = (tlx + trx) / 2;
    int r1 = min_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry);
    int r2 = min_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
    return max(r1,r2);
}

int main()
{
    
    return 0;
}