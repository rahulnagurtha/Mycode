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
 
#define LMT 1005
#define INF (1 << 30)
 
 
ll a[LMT][LMT];
ll m , n ;
 
 
ll q,A,B;
ll pow2[15];
ll rnda,rndb;
ll Sum[LMT][LMT];
ll X1, Y1, X2, Y2;
ll offseta,offsetb;
ll dp[LMT][LMT][11][11];


void init() {
    ll tmp;
    for (ll i = 1; i <= n; ++i) {
        tmp = 0;
        for (ll j = 1; j <= m; ++j) {
            tmp += a[i][j];
            Sum[i][j] = Sum[i-1][j] + tmp;
        }
    }
    for (int i = 0; i < 13; ++i) {
        pow2[i] = 1 << i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j][0][0] = a[i][j];
        }
    }
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k+pow2[i-1] <= m; ++k) {
                dp[j][k][0][i] = max(dp[j][k][0][i-1],dp[j][k+pow2[i-1]][0][i-1]);
            }
        }
    }
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j+pow2[i-1] <= n; ++j) {
            for (int k = 1; k <= m; ++k) {
                dp[j][k][i][0] = max(dp[j][k][i-1][0],dp[j+pow2[i-1]][k][i-1][0]);
            }
        }
    }

    for (int p = 1; p < 11; ++p) {
        for (int q = 1; q < 11; ++q) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j+pow2[q-1] <= m; ++j) {
                    dp[i][j][p][q] = max(dp[i][j][p][q-1],dp[i][j+pow2[q-1]][p][q-1]);
                }
            }
        }
    }
    return;
}

 
int main(void) {
    ll ans;
    ll tmp;
    ll tmp1;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    init();
    cin >> q;
    for (ll i = 0; i < q; ++i)
    {
        ans = 1000000007LL;
        cin >> A >> B;
        rnda = log2(A);
        rndb = log2(B);
        offseta = A - pow2[rnda];
        offsetb = B - pow2[rndb];
        for (X1 = 1; X1 + A - 1 <= n; ++X1) {
            for (Y1 = 1; Y1 + B - 1 <= m; ++Y1) {
                tmp = (max(max(dp[X1][Y1][rnda][rndb],dp[X1+offseta][Y1+offsetb][rnda][rndb]),max(dp[X1][Y1+offsetb][rnda][rndb],dp[X1+offseta][Y1][rnda][rndb])))*(A*B) - (Sum[X1 + A - 1][Y1 + B - 1] - Sum[X1-1][Y1 + B - 1] - Sum[X1 + A - 1][Y1-1] + Sum[X1-1][Y1-1]);
                ans = min(ans,tmp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}