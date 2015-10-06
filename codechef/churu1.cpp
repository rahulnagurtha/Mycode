//Coder: Balajiganapathi
#ifndef ONLINE_JUDGE
#   define DEBUG
#   define TRACE
#else
//#   define NDEBUG
#endif
 
#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <forward_list>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;
 
// Basic macros
#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define rev(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define repv(i,n,s) for(int i=(n);i>=s;--i)
#define fov(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define si(x)       (int)(x.size())
 
#ifdef TRACE
    #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
    #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
    #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
#else
    #define trace(x)
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
    #define trace4(a,b,c,d)
    #define trace5(a,b,c,d,e)
    #define trace6(a,b,c,d,e,f)
#endif
 
 
static struct IO {
	char tmp[1 << 10];
 
	// fast input routines
	char cur;
 
//#define nextChar() (cur = getc(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getchar_unlocked(); }
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
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }
 
	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}
 
#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
		} \
		return *this; \
	}
 
defineInFor(int)
 
	// fast output routines
 
//#define putChar(c) putc((c), stdout)
	inline void putChar(char c) { putchar_unlocked(c); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
 
	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
 
	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }
 
 
#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }
 
defineOutFor(unsigned long long)
 
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
 
 
 
const int oo = 1000000009;
const double eps = 1e-6;
const int mod = 1000000007;
const int mx = 100005, sq_mx = 400, lg_mx = 17;
const int seg_mx = 2 * (1 << lg_mx) - 1;
 
int num[mx], n, l[mx], r[mx];
ll f[mx];
ll seg[seg_mx], bsum[sq_mx];
int cnt[seg_mx][sq_mx];
vector<int> segs[mx];
int s, ns;
 
int qc[mx], qa[mx], qb[mx], cnt1, cnt2;
 
int idx, bi, diff;
void init_sum(int i, int a, int b) {
    if(a == b) {
        seg[i] = num[a];
        return;
    }
 
    int m = (a + b) / 2, l = 2 * i + 1, r = 2 * i + 2;
    init_sum(l, a, m);
    init_sum(r, m + 1, b);
    seg[i] = seg[l] + seg[r];
}
 
void init_seg(int i, int a, int b, int qa, int qb) {
    if(a == qa && b == qb) {
        f[idx] += seg[i];
        cnt[i][bi] += 1;
        segs[idx].pu(i);
        return;
    }
    int m = (a + b) / 2, l = 2 * i + 1, r = 2 * i + 2;
    if(qb <= m) {
        init_seg(l, a, m, qa, qb);
    } else if(qa > m) {
        init_seg(r, m + 1, b, qa, qb);
    } else {
        init_seg(l, a, m, qa, m);
        init_seg(r, m + 1, b, m + 1, qb);
    }
}
 
void display() {
    fo(i, n) trace3(i, num[i], f[i]);
    fo(i, ns) trace2(i, bsum[i]);
}
 
void init() {
    int k = ceil(log(n) / log(2));
    if(k * cnt2 == 0) s = n;
    else s = max((int)ceil(sqrt((2.0 * cnt2 * n + 1.0 * cnt1 * k * n) / (4.0 * cnt2 * k))), n / (sq_mx - 2));
    ns = (n + s - 1) / s;
    assert(ns < sq_mx);
    trace4(n, ns, s, k);
 
    init_sum(0, 0, n - 1);
    fo(i, n) {
        idx = i;
        bi = i / s;
        init_seg(0, 0, n - 1, l[i], r[i]);
        bsum[bi] += f[i];
    }
    //display();
}
 
void update(int i) {
    f[i] = 0;
    for(auto x: segs[i]) {
        f[i] += seg[x];
    }
}
 
inline ull get(int &a, int &b) {
    ull ret = 0;
    int cnt = (s - a % s) % s;
    for(; cnt-- && a <= b; ++a) {
        update(a);
        ret += f[a];
    }
 
    cnt = (1 + b % s) % s;
    for(; cnt-- && a <= b; --b) {
        update(b);
        ret += f[b];
    }
 
    if(a <= b) {
        for(int i = a / s; i <= b / s; ++i) {
            ret += bsum[i];
        }
    }
 
    return ret;
}
 
void change_seg(int i, int a, int b) {
    while(a <= b) {
        seg[i] += diff;
        fo(j, ns) bsum[j] += (ll)cnt[i][j] * diff;
        if(a == b) return;
        int m = (a + b) / 2, l = 2 * i + 1, r = 2 * i + 2;
        if(idx <= m) {
            i = l; b = m;
        } else {
            i = r; a = m + 1;
        }
    }
}
 
inline void change(int x, int y) {
    idx = x; diff = y - num[x];
    change_seg(0, 0, n - 1);
    num[x] = y;
}
 
int main() {
    cin >> n;
    fo(i, n) cin >> num[i];
    fo(i, n) {
        cin >> l[i] >> r[i];
        --l[i]; --r[i];
    }
 
    int q, c, x, y;
    cin >> q;
 
    fo(i, q) {
        cin >> c >> x >> y;
        if(c == 1) {
            --x;
            ++cnt1;
        } else {
            --x; --y;
            ++cnt2;
        }
        qc[i] = c; qa[i] = x; qb[i] = y;
    }
    init();
 
    fo(i, q) {
        if(qc[i] == 1) change(qa[i], qb[i]);
        else cout << get(qa[i], qb[i]) << endl;
    }
 
	return 0;
}