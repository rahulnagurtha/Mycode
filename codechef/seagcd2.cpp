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
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }
 
	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}
 
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


ll a[100005];
ll dp[100005][105];
ll n,m;
ll fact[100005];

ll prime[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void preprocess() {
	dp[0][0] = 1;
	for (int i = 1; i <= 100005; ++i) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for (int j = 1; j <= 101; ++j) {
		for (int i = 2; i <= 100001; ++i) {
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%MOD;
		}
	}
	fact[0] = 1;
	for (int i = 1; i < 100005; ++i) {
		fact[i] = (fact[i-1]*i) % MOD;
	}
	return;
}


ll two() {
	ll cnt = 0;
	if(2 <= m) cnt++;
	if(4 <= m) cnt++;
	if(8 <= m) cnt++;
	if(16 <= m) cnt++;
	if(32 <= m) cnt++;
	if(64 <= m) cnt++;
	return cnt;
}

ll three() {
	ll cnt = 0;
	if(3 <= m) cnt++;
	if(9 <= m) cnt++;
	if(27 <= m) cnt++;
	if(81 <= m) cnt++;
	return cnt;
}

ll five() {
	ll cnt = 0;
	if(5 <= m) cnt++;
	if(25 <= m) cnt++;
	return cnt;
}

ll seven() {
	ll cnt = 0;
	if(7 <= m) cnt++;
	if(49 <= m) cnt++;
	return cnt;
}

ll total() {
	ll cnt = 0;
	for (int i = 0; i < 25; ++i) {
		if(prime[i] <= m) cnt++;
	}
	return cnt;
}


int main()
{
	preprocess();
    int t;
    cin >> t ;
    while(t--) {
    	ll tot,ans = 0;
    	ll mf = 1;
    	ll tmp;
    	cin >> n >> m ;
    	tot = total();
    	if(tot >= 1) mf = mf*two();
    	if(tot >= 2) mf = mf*three();
    	if(tot >= 3) mf = mf*five();
    	if(tot >= 4) mf = mf*seven();
    	for (int i = 0; i <= tot; ++i) {
    		// cout << dp[tot][i] << " " << dp[n][i] << " " << fact[i] << endl;
    		tmp = ((dp[n][i])*fact[i])%MOD;
    		ans = ans + (dp[tot][i]*tmp)%MOD;
    		ans = ans % MOD;
    	}
    	ans = (ans*mf)%MOD;
    	cout << ans << endl;
    }
    return 0;
}