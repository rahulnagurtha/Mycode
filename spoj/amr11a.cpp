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




#define ROWS	505
#define COLUMNS 505


int R,C,temp;
int val[ROWS][COLUMNS];
int dp[ROWS][COLUMNS];



void solve() {
	for (int i = R-1; i >= 1; --i) {
		for (int j = C-1; j >= 1; --j) {
			temp = max(dp[i+1][j],dp[i][j+1]);
			dp[i][j] = min(val[i][j],val[i][j] + temp);
		}
	}
	if (dp[1][1] > 0) printf("1\n");
	else printf("%d\n",1-dp[1][1]);
}



void initdata() {
	dp[R][C] = 0;
	for (int i = C-1; i >= 1 ; --i) {
		temp = dp[R][i+1];
		dp[R][i] = min(val[R][i],val[R][i] + temp);
	}
	for (int i = R-1; i >= 1 ; --i) {
		temp = dp[i+1][C];
		dp[i][C] = min(val[i][C],val[i][C] + temp);
	}
}


void readdata() {
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			// scanf("%d",&val[i][j]);
			cin >> val[i][j];
		}
	}
}


// void printdata() {
// 	for (int i = 1; i <= R; ++i) {
// 		for (int j = 1; j <= C; ++j) {
// 			printf("%d ",dp[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");
// }


int main()
{
	// freopen("in.txt", "r", stdin);
	int t;
	cin >> t ;
    while(t--) {
    	cin >> R >> C ;
    	readdata();
    	initdata();
    	solve();
    	// printdata();
    }
    return 0;
}