#include <bits/stdc++.h>

using namespace std;



static struct IO {
    char tmp[1 << 10];
 
    // fast input routines
    char cur;
 
//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
    inline char nextChar() { return cur = getc_unlocked(stdin); }
    inline char peekChar() { return cur; }
 
    inline operator bool() { return peekChar(); }
    inline static bool isBlank(char c) { return (c < '-' && c); }
    inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }
 
    inline IO& operator >> (char & c) { c = nextChar(); return *this; }
 
    inline IO& operator >> (char * buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar())) *(buf++) = peekChar();
            } *(buf++) = 0; } return *this; }
 
    inline IO& operator >> (string & s) {
        if (skipBlanks()) {    s.clear(); s += peekChar();
            while (!isBlank(nextChar())) s += peekChar(); }
        return *this; }
 
    inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;    }
 
#define defineInFor(intType) \
    inline IO& operator >>(intType & n) { \
        if (skipBlanks()) { \
            int sign = +1; \
            if (peekChar() == '-') { \
                sign = -1; \
                n = nextChar() - '0'; \
            } else \
                n = peekChar() - '0'; \
            while (!isBlank(nextChar())) { \
                n += n + (n << 3) + peekChar() - 48; \
            } \
            n *= sign; \
        } \
        return *this; \
    }
 
defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)
 
    // fast output routines
 
//#define putChar(c) putc_unlocked((c), stdout)
    inline void putChar(char c) { putc_unlocked(c, stdout); }
    inline IO& operator << (char c) { putChar(c); return *this; }
    inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
 
    inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
 
    char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
    inline IO& operator << (double d) { return (*this) << toString(d); }
 
 
#define defineOutFor(intType) \
    inline char * toString(intType n) { \
        char * p = (tmp + 30); \
        if (n) { \
            bool isNeg = 0; \
            if (n < 0) isNeg = 1, n = -n; \
            while (n) \
                *--p = (n % 10) + '0', n /= 10; \
            if (isNeg) *--p = '-'; \
        } else *--p = '0'; \
        return p; \
    } \
    inline IO& operator << (intType n) { return (*this) << toString(n); }
 
defineOutFor(int)
defineOutFor(long long)
 
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;



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

#define LMT 1030

int m,n;
int sum[3*LMT][3*LMT];
int tmx,my,tmy,r1,r2,rr1,rr2;


void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int xx, int yy, int val) {
    if (ly == ry) {
        if (lx == rx){
            sum[vx][vy] = val;
        }        
        else {
            sum[vx][vy] = sum[vx << 1][vy] + sum[(vx << 1) + 1][vy];
        }
    }
    else {
        my = (ly + ry) >> 1;
        if(my >= yy) update_y(vx, lx, rx, vy << 1, ly, my, xx, yy, val);
        else update_y(vx, lx, rx, (vy << 1)+1, my+1, ry, xx, yy, val);
        sum[vx][vy] = sum[vx][vy << 1] + sum[vx][1 + (vy << 1)];
    }
    return;
}

void update_x(int vx, int tlx, int trx, int xx,int yy,int val) {
    if (tlx != trx) {
        tmx = (tlx + trx) >> 1;
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
    r1 = sum_y(vx, vy << 1, tly, tmy, ly, min(ry,tmy));
    r2 = sum_y(vx, (vy << 1)+1, tmy+1, try_, max(ly,tmy+1), ry);
    return r1 + r2;
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y (vx, 1, 1, m, ly, ry);
    tmx = (tlx + trx) >> 1;
    rr1 = sum_x (vx << 1, tlx, tmx, lx, min(rx,tmx), ly, ry);
    rr2 = sum_x ((vx << 1)+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
    return rr1 + rr2;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        fill(sum,0);
        int x,y,num;
        int x1,x2,y1,y2;
        string type;
        cin >> n;
        m = n;
        while(1) {
            cin >> type;
            if(type == "SET") {
                cin >> x >> y >> num;
                x++;
                y++;
                update_x(1,1,n,x,y,num);
            }
            else if(type == "SUM") {
                cin >> x1 >> y1 >> x2 >> y2;
                x1++;x2++;
                y1++;y2++;
                cout << sum_x(1,1,n,x1,x2,y1,y2) << endl;
            }
            else break;
        }
        cout << endl;
    }
    return 0;
}