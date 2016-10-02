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

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define Ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int n,q,bsiz,total,l,r,x,lft,ryt,bnum,ans;
int lblock,rblock,tmp;

char type;

struct node {
    int val;
    int pos;
};

node a[100005];


bool compare(const node lhs, const node rhs) { 
    return lhs.val <= rhs.val ; 
}


int bsearch(int left,int right,int value) {
    if(left == right) return left;
    int mid = (left+right)/2;
    if(a[mid].val > value) {
        return bsearch(left,mid,value);
    }
    else {
        return bsearch(mid+1,right,value);
    }
}



int main()
{
    cin >> n >> q;
    bsiz = ceil(sqrt(n));
    total = Ceil(n,bsiz);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].val;
        a[i].pos = i;
    }
    for (int i = 1; i <= total; ++i) {
        l = (i-1)*bsiz + 1;
        r = min(n,i*bsiz) + 1;
        sort(a+l,a+r,compare);
    }
    for (int i = 0; i < q; ++i) {
        cin >> type;
        if(type == 'M') {
            cin >> l >> x;
            bnum = Ceil(l,bsiz);
            lft = (bnum-1)*(bsiz)+1;
            ryt = min(bnum*bsiz,n) + 1;
            for (int i = lft; i < ryt; ++i) {
                if(a[i].pos == l) {
                    a[i].val = x;
                    break;
                }
            }
            sort(a+lft,a+ryt,compare);
        }
        else {
            cin >> l >> r >> x;
            ans = 0;
            lblock = Ceil(l,bsiz);
            rblock = Ceil(r,bsiz);
            if(lblock == rblock) {
                lft = (lblock-1)*bsiz+1;
                ryt = min(n,lblock*bsiz);
                for (int i = lft; i <= ryt; ++i) {
                    if(a[i].pos >= l && a[i].pos <= r && a[i].val <= x) ans++; 
                }
                printf("%d\n",ans);
            }
            else {
                if(l%bsiz != 1) {
                    lft = (lblock-1)*bsiz+1;
                    ryt = lblock*bsiz;
                    for (int i = lft; i <= ryt; ++i) {
                        if(a[i].pos >= l && a[i].pos <= r && a[i].val <= x) {
                            ans++;
                        }
                    }
                    lblock++;
                }
                if(r%bsiz != 0) {
                    lft = (rblock - 1)*bsiz+1;
                    ryt = rblock*bsiz;
                    for (int i = lft; i <= ryt; ++i) {
                        if(a[i].pos >= l && a[i].pos <= r && a[i].val <= x) {
                            ans++;
                        }
                    }
                    rblock--;
                }
                while(lblock <= rblock) {
                    lft = 1 + (lblock-1)*bsiz;
                    ryt = min(lblock*bsiz,n);
                    if(a[ryt].val <= x) ans = ans + ryt - lft + 1;
                    else ans = ans + bsearch(lft,ryt,x) - lft;
                    lblock++;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
