#include <bits/stdc++.h>
 
using namespace std;

#define MOD  1000000007
 
typedef long long int ll;
 
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
 
 
 
 
struct tree {
    ll add,mul,init,sum;
};
 
tree part[300001];
int arr[100005];
 
void build(ll node,ll i,ll j) {
    if(i>j) return;
    if(i==j) {                        
        part[node].sum = arr[i];
        part[node].add = part[node].init = 0;
        part[node].mul = 1;
        return;
    }
    build(node*2,i,(i+j)/2);
    build(node*2+1,1+(i+j)/2,j);
    part[node].sum = (part[node*2].sum + part[1+node*2].sum) % MOD;
    part[node].add = part[node].init = 0;
    part[node].mul = 1;
    return;
}

inline void routine(ll node,ll a,ll b,ll i,ll j) {
    if(part[node].init != 0 && a != b) {
            part[node*2].sum = part[1+2*node].sum = 0;
            part[node*2].add = part[1+node*2].add = part[node].add; 
            part[node*2].mul = part[1+node*2].mul = part[node].mul;
            part[node*2].init = part[1+node*2].init = part[node].init;
            part[node].sum = ((part[node].sum*part[node].mul)%MOD+((b-a+1)*part[node].add)%MOD)%MOD;
            part[node].add = part[node].init = 0;
            part[node].mul = 1;
    }
    if(part[node].add != 0 || part[node].mul != 1) {
        part[node].sum = ((part[node].sum*part[node].mul)%MOD+((b-a+1)*part[node].add)%MOD)%MOD;
        if(a != b) {
            part[node*2].add = (part[node*2].add*part[node].mul) % MOD;
            part[node*2].mul = (part[node*2].mul*part[node].mul) % MOD;
            part[node*2].add = (part[node*2].add+part[node].add) % MOD;
            
            part[1+node*2].add = (part[1+node*2].add*part[node].mul) % MOD;
            part[1+node*2].mul = (part[1+node*2].mul*part[node].mul) % MOD; 
            part[1+node*2].add = (part[1+node*2].add+part[node].add) % MOD;
        }
        part[node].add = 0;
        part[node].mul = 1;
    }
}
 

ll qsum(ll node,ll a,ll b,ll i,ll j) {
    if(a > b || a > j || b < i) return 0;
    routine(node,a,b,i,j);
    if(a >= i && b <= j) return part[node].sum%MOD;
    ll q1,q2; 
    q1 = qsum(node*2, a, (a+b)/2, i, j);    
    q2 = qsum(1+node*2, 1+(a+b)/2, b, i, j);
    ll res = (q1+q2) % MOD;
    return res;
}
 
 
void updadd(ll node, ll a, ll b, ll i, ll j, ll value) {
 
    routine(node,a,b,i,j);
    if(a > b || a > j || b < i) 
        return;
    if(a >= i && b <= j) {
        part[node].sum = (part[node].sum+((b-a+1)*value)%MOD) % MOD;
        if(a != b) {
            part[node*2].add = (part[node*2].add + value) % MOD;
            part[node*2+1].add = (part[node*2+1].add + value) % MOD;
        }
        return;
    }
    updadd(node*2, a, (a+b)/2, i, j, value);
    updadd(1+node*2, 1+(a+b)/2, b, i, j, value); 
    part[node].sum = (part[node*2].sum + part[1+node*2].sum)%MOD;
}
 
void updmul(ll node, ll a, ll b, ll i, ll j, ll value) {
 
    routine(node,a,b,i,j);
    if(a > b || a > j || b < i) 
        return;
    if(a >= i && b <= j) {
        part[node].sum = (part[node].sum*value)%MOD;
        if(a != b) {
            part[node*2].add = (part[node*2].add*value)%MOD;
            part[node*2].mul = (part[node*2].mul*value)%MOD;
            part[1+node*2].add = (part[1+node*2].add*value)%MOD;
            part[1+node*2].mul = (part[1+node*2].mul*value)%MOD;
        }
        return;
    }
    updmul(node*2, a, (a+b)/2, i, j, value);
    updmul(1+node*2, 1+(a+b)/2, b, i, j, value); 
    part[node].sum = (part[node*2].sum + part[1+node*2].sum)%MOD;    
}
 
void updinit(ll node, ll a, ll b, ll i, ll j, ll value) {
    
    routine(node,a,b,i,j);
    if(a > b || a > j || b < i) 
        return;
    if(a >= i && b <= j) {
        part[node].sum = ((b-a+1)*value)%MOD;
        if(a != b) {
            part[node*2].add = part[1+node*2].add = value;
            part[node*2].mul = part[1+node*2].mul = 1;
            part[node*2].sum = part[1+node*2].sum = 0;
            part[node*2].init = part[1+node*2].init = 1;
        }
        return;
    }
    updinit(node*2, a, (a+b)/2, i, j, value);
    updinit(1+node*2, 1+(a+b)/2, b, i, j, value); 
    part[node].sum = (part[node*2].sum + part[1+node*2].sum)%MOD;
}
 
// main code begins now
 
int main()
{
    ll n,q,type,x,y,v;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    build(1,1,n);
    for (int i = 0; i < q; ++i) {
        cin >> type;
        if(type == 1) {
            cin >> x >> y >> v;
            updadd(1,1,n,x,y,v);
        }
        else if(type == 2) {
            cin >> x >> y >> v;
            updmul(1,1,n,x,y,v);
        }
        else if(type == 3) {
            cin >> x >> y >> v;
            updinit(1,1,n,x,y,v);
        }
        else {
            cin >> x >> y;
            cout<< qsum(1,1,n,x,y) << endl;
        }
    }
    return 0;
}