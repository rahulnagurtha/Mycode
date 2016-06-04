/*
http://codeforces.com/blog/entry/3327
 */
 
 
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
 
 
 
 
#define Max 1005
#define INF (1 << 30)
typedef long long int ll;
 
ll P[Max][Max];
 

int T[2 * Max * Max];

struct Segtree2d {
 
    int build(int node, int a1, int b1, int a2, int b2) {
        if (a1 > a2 or b1 > b2)
            return -INF;
 
        if (a1 == a2 and b1 == b2)
            return T[node] = P[a1][b1];
 
        T[node] = -INF;
        T[node] = max(T[node], build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) );
        T[node] = max(T[node], build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));
        T[node] = max(T[node], build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) );
        T[node] = max(T[node], build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2) );
        return T[node];
    }

    int query(int node, int a1, int b1, int a2, int b2, int X1, int Y1, int X2, int Y2) {
        if (X1 > a2 or Y1 > b2 or X2 < a1 or Y2 < b1 or a1 > a2 or b1 > b2)
            return -INF;
 
        if (X1 <= a1 and Y1 <= b1 and a2 <= X2 and b2 <= Y2)
            return T[node];
 
        int mx = -INF;
        mx = max(mx, query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, X1, Y1, X2, Y2) );
        mx = max(mx, query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, X1, Y1, X2, Y2) );
        mx = max(mx, query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, X1, Y1, X2, Y2) );
        mx = max(mx, query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, X1, Y1, X2, Y2));
        return mx;
    }
};
 
int n,m,t,a,b;
Segtree2d Tmax;
ll Sum[1005][1005];
int X1, Y1, X2, Y2;
 
void init() {
    ll tmp;
    Tmax.build(1,1,1,n, m);
    for (ll i = 1; i <= n; ++i) {
        tmp = 0;
        for (ll j = 1; j <= m; ++j) {
            tmp += P[i][j];
            Sum[i][j] = Sum[i-1][j] + tmp;
        }
    }
    return;
}
 
inline ll getSum() {
    return Sum[X2][Y2] - Sum[X1-1][Y2] - Sum[X2][Y1-1] + Sum[X1-1][Y1-1];
}
 
int main(void) {
    ll ans;
    ll tmp;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            cin >> P[i][j];
        }
    }
    init();
    cin >> t;
    for (ll i = 0; i < t; ++i)
    {
        ans = 1000000007LL;
        cin >> a >> b;
        for (X1 = 1; X1 + a - 1 <= n; ++X1) {
            X2 = X1 + a - 1;
            for (Y1 = 1; Y1 + b - 1 <= m; ++Y1) {
                Y2 = Y1 + b - 1;
                tmp = 0;
                // cout << X1 << "," << Y1 << " <-> " << X2 << "," << Y2 << "  : " << (Tmax.query(X1,Y1,X2,Y2).mx)*(a*b) << " - " << getSum() << endl;
                tmp = ((ll)Tmax.query(1, 1, 1, n, m,X1,Y1,X2,Y2))*(a*b) - getSum();
                ans = min(ans,tmp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}