#include <bits/stdc++.h>
using namespace std;
 
/*------- Constants---- */
#define LMT             605
#define ll              long long
#define ull             unsigned long long
#define mod             1000000007
#define MEMSET_INF      63
#define MEM_VAL         1061109567
#define FOR(i,n)            for( int i=0 ; i < n ; i++ )
#define mp(i,j)         make_pair(i,j)
#define lop(i,a,b)      for( int i = (a) ; i < (b) ; i++)
#define pb(a)           push_back((a))
#define gc              getchar_unlocked
#define PI              acos(-1.0)
#define inf             1<<30
#define lc              ((n)<<1)
#define rc              ((n)<<1 |1)
#define msg(x)          cout<<x<<endl;
 
/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
typedef pair<int, int> ii;
typedef vector<int > vi ;
/*------ template functions ------ */
inline void sc(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 | c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
 
template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
 
/*************************** END OF TEMPLATE ****************************/
 
int t[4*LMT][4*LMT];
int p[4*LMT][4*LMT];
int a[LMT][LMT];
int m , n ;
void build_y (int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry)
        if (lx == rx){
            t[vx][vy] = a[lx][ly];
            p[vx][vy] = a[lx][ly];
        }
             
        else {
            t[vx][vy] = max(t[vx*2][vy] , t[vx*2+1][vy] );
            p[vx][vy] = min(p[vx*2][vy] , p[vx*2+1][vy] );
        }
     
        else {
            int my = (ly + ry) / 2;
            build_y (vx, lx, rx, vy*2, ly, my);
            build_y (vx, lx, rx, vy*2+1, my+1, ry);
            t[vx][vy] = max(t[vx][vy *2] , t[vx][vy *2 + 1]);
            p[vx][vy] = min(p[vx][vy *2] , p[vx][vy *2 + 1]);
        }
}
 
void build_x (int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x (vx*2, lx, mx);
        build_x (vx*2+1, mx+1, rx);
    }
    build_y (vx, lx, rx, 1, 0, m-1);
}
 
 
void update_y (int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx){
            t[vx][vy] = new_val;
            p[vx][vy] = new_val;
        }
        else {
            t[vx][vy] = max(t[vx*2][vy] , t[vx*2+1][vy] );
            p[vx][vy] = min(p[vx*2][vy] , p[vx*2+1][vy] );
        }
         
    }
    else {
        int my = (ly + ry) / 2;
        if (y <= my) update_y (vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else update_y (vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
         
        t[vx][vy] = max(t[vx][vy *2] , t[vx][vy *2 + 1]);
        p[vx][vy] = min(p[vx][vy *2] , p[vx][vy *2 + 1]);
    }
}
 
void update_x (int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx) update_x (vx*2, lx, mx, x, y, new_val);
        else update_x (vx*2+1, mx+1, rx, x, y, new_val);
    }
    update_y (vx, lx, rx, 1, 0, m-1, x, y, new_val);
}
 
 
ii query_y (int vx, int vy, int tly, int try_, int ly, int ry) {
     
    if (ly > ry) return ii(-1,inf );
     
    if (ly == tly && try_ == ry) return ii( t[vx][vy] ,p[vx][vy]);
     
    int tmy = (tly + try_) / 2;
     
    ii r1 = query_y (vx, vy*2, tly, tmy, ly, min(ry,tmy));
    ii r2 = query_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry);
     
    return ii( max(r1.first , r2.first) , min(r1.second, r2.second)) ;
     
}
 
ii query_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return ii(-1,inf );
    if (lx == tlx && trx == rx)
        return query_y (vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
     
    ii r1 = query_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry);
    ii r2 = query_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
     
    return ii( max(r1.first , r2.first) , min(r1.second, r2.second)) ;
}
 
int val ;
 
int main()
{
     
     
     
 
    int  q ;
    sc(n); sc(m);
    FOR(i , n) FOR(j , m) sc(a[i][j]);
     
     
    build_x(1, 0 , n-1);
     
    sc(q);
     
    char ch ;
    int x1,  x2 , y1 , y2;
    while (q -- ) {
        do {
            ch = gc();
        } while (ch =='\n'||ch =='\0');
         
        if(ch == 'q') {
            sc(x1) ; sc(y1) ;sc(x2);sc(y2);
            x1 -- , y1 -- ,x2 -- , y2 --;
            ii r = query_x( 1, 0 , n -1 , x1 , x2 , y1 , y2);
            printf("%d %d\n" ,r.first , r.second);
        }
        else {
            sc(x1) ;sc(y1 );sc(val);
            x1 -- , y1--;
            update_x(1, 0, n-1 ,x1 , y1,val);
        }
         
    }
     
    return 0;
}