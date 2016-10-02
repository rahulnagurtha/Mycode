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



#define si(i) 					scanf("%d",&i)
#define slli(i) 				scanf("%I64d",&i)

#define pi(i) 					printf("%d\n",i)
#define plli(i) 				printf("%I64d\n",i)

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			    ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			    (a-(box(a,b))*b)
#define ceil(a,b) 			    ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			    ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int n,a[100005],dp[320][100003],m,block,total;
LL part[500001],bsum[320],pre[100005];
VOII q(100005);

void build(int node,int i,int j) {
	if(i>j) return;
	if(i==j) {						
		part[node] = (LL)a[i];
		return;
	}
	build(node*2,i,(i+j)/2);
	build(node*2+1,1+(i+j)/2,j);
	part[node] = part[node*2] + part[1+node*2];
	return;
}

LL query_sum(int node,int a,int b,int i,int j) {
	if(a > b || a > j || b < i) return 0;
	if(a >= i && b <= j) return part[node];
	LL q1,q2;
	q1 = query_sum(node*2, a, (a+b)/2, i, j);
	q2 = query_sum(1+node*2, 1+(a+b)/2, b, i, j);
	LL res = q1 + q2;
	return res;
}

void update(int node,int pos,int i,int j,int val) {
    if(i>j) return;
    if(i==j && i==pos) {			
        part[node] = val;
        return;
    }
    if(i<=pos && j>=pos) {
        update(2*node,pos,i,(i+j)/2,val);
        update(2*node+1,pos,(i+j)/2 + 1,j,val);
        part[node] = part[2*node] + part[1+2*node];
    	return;
    }
}

void Read() {
	q[0].FF = q[0].SS = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pre[i] = ((LL)a[i]) + pre[i-1];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> q[i].FF >> q[i].SS;
		// si(q[i].FF);si(q[i].SS);
	}
	cin >> m;
	// si(m);
	return;
}

void brute() {
	int l,r,type;
	LL ans;
	for (int i = 0; i < m; ++i) {
		ans = 0;
		cin >> type >> l >> r;
		// si(type);si(l);si(r);
		if(type == 1) {
			a[l] = r;
			continue;
		}
		for (int j = l; j <= r; ++j) {
			for (int k = q[j].FF; k <= q[j].SS; ++k) {
				ans += a[k];
			}
		}
		cout << ans << endl;
		// printf("%lld\n",ans);
	}
	return;
}

void preprocess() {
	block = sqrt(n);
	total = ceil(n,block);
	for (int i = 1; i <= total; ++i) {
		for (int j = block*(i-1) + 1; j <= block*i && j <= n; ++j) {
			bsum[i] += (pre[q[j].SS] - pre[q[j].FF-1]);
			dp[i][q[j].FF]++;
			dp[i][1 + q[j].SS]--;
		}
		for (int j = 1; j <= n; ++j) {
			dp[i][j] += dp[i][j-1];
		}
	}
	return;
}

void solve() {
	int l,r,lb,rb,type;
	build(1,1,n);
	preprocess();
	LL ans;
	for (int i = 0; i < m; ++i) {
		cin >> type >> l >> r ;
		if(type == 1) {
			update(1,l,1,n,r);
			for (int i = 1; i <= total; ++i) bsum[i] += dp[i][l]*(r-a[l]);
			a[l] = r;
		}
		else {
			ans = 0;
			lb = ceil(l,block);
			rb = ceil(r,block);
			if(lb == rb) {
				for (int j = l; j <= r; ++j) ans += query_sum(1,1,n,q[j].FF,q[j].SS);
			}
			else {
				if(l % block != 1) lb++;
				if(r % block != 0) rb--;
				for (int j = l; j % block != 1 && j <= n; ++j,++l) ans += query_sum(1,1,n,q[j].FF,q[j].SS);
				for (int j = r; j % block != 0; --j,--r) ans += query_sum(1,1,n,q[j].FF,q[j].SS);
				if(l < r) {
					for (int j = lb; j <= rb; ++j) ans += bsum[j];
				}
			}
			cout << ans << endl;
			// printf("%lld\n",ans);
		}
	}
}

// main code begins now

int main()
{
    // si(n);
    cin >> n ;
    Read();
    if(n < 4) brute();
    else solve();
    return 0;
}