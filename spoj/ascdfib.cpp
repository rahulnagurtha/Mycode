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





long long int A,B,cnt,fibonacci[100005];

void initialise() {
    fibonacci[1] = 0;
    fibonacci[2] = 1;
    for (int i = 3; i <= 100005; ++i) {
        fibonacci[i] = (fibonacci[i-1] + fibonacci[i-2])%100000;
    }
    return;
}

void solve() {
    vector<long long int> toprint;
    long long int fir,sec,tmp;
    fir = fibonacci[A]%100000;
    sec = fibonacci[A+1]%100000;
    toprint.push_back(fir);
    toprint.push_back(sec);
    for (long long int i = A + 2; i <= A+B; ++i) {
        tmp = (fir + sec)%100000;
        fir = sec ;
        sec = tmp ;
        toprint.push_back(tmp);
    }
    sort(toprint.begin(),toprint.end());
    cout << "Case " << cnt << ": ";
    // printf("Case %lld: ",cnt);
    if(toprint.size() <= 100) {
        for (int i = 0; i < toprint.size(); ++i) {
            // printf("%lld ",toprint[i]);
            cout << toprint[i] << " ";
        }
    }
    else {
        for (int i = 0; i < 100; ++i) {
            // printf("%lld ",toprint[i]);
            cout << toprint[i] << " ";
        }
    }
    // printf("\n");
    cout << endl;
}



// main code begins now

int main()
{
    initialise();
    int t;
    cnt = 1;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
        cin >> A >> B ;
        solve();
    }
    return 0;
}