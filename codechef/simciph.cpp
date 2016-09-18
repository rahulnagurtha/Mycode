#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif



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
#define INF                     INT_MAX
#define N                       100007


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



VS bag[6];

inline void Refresh() {
    for (int i = 0; i < 6; ++i) {
    	bag[i].clear();
    }
}


int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
        int n;
        ll ans = 0;
        cin >> n;
        string A[5];
        string original[5];
        for (int i = 0; i < n; ++i) {
        	cin >> A[i];
        	original[i] = A[i];
        	sort(A[i].begin(),A[i].end());
        	do {
        		bag[i].pb(A[i]);
			} while(next_permutation(A[i].begin(),A[i].end()));
        }
        // printf("here");
        if(n == 1) {
        	for (int one = 0; one < bag[0].size(); ++one) {
        		char mapping[26];
        		bool isValid = true;
	        	for (int j = 0; j < 26; ++j) {
	        		mapping[j] = '?';	
	        	}
	        	//one
        		for (int j = 0; j < bag[0][one].size(); ++j) {
        			if(mapping[original[0][j]-'A'] == '?') {
        				mapping[original[0][j]-'A'] = bag[0][one][j];
        			}
        			else {
        				if(mapping[original[0][j]-'A'] != bag[0][one][j]) {
        					isValid = false;
        					break;
        				}
        			}
        		}
        		if(isValid) ans++;
        	}
        }
        if(n == 2) {
        	for (int one = 0; one < bag[0].size(); ++one) {
        		for (int two = 0; two < bag[1].size(); ++two) {
        			char mapping[26];
	        		bool isValid = true;
		        	for (int j = 0; j < 26; ++j) {
		        		mapping[j] = '?';	
		        	}
		        	//one
	        		for (int j = 0; j < bag[0][one].size(); ++j) {
	        			if(mapping[original[0][j]-'A'] == '?') {
	        				mapping[original[0][j]-'A'] = bag[0][one][j];
	        			}
	        			else {
	        				if(mapping[original[0][j]-'A'] != bag[0][one][j]) {
	        					isValid = false;
	        					break;
	        				}
	        			}
	        		}
	        		if(!isValid) break;
	        		//two
	        		for (int j = 0; j < bag[1][two].size(); ++j) {
	        			if(mapping[original[1][j]-'A'] == '?') {
	        				mapping[original[1][j]-'A'] = bag[1][two][j];
	        			}
	        			else {
	        				if(mapping[original[1][j]-'A'] != bag[1][two][j]) {
	        					isValid = false;
	        					break;
	        				}
	        			}
	        		}
	        		if(isValid) ans++;
        		}
        	}
        }
        if(n == 3) {
        	for (int one = 0; one < bag[0].size(); ++one) {
        		for (int two = 0; two < bag[1].size(); ++two) {
        			for (int three = 0; three < bag[2].size(); ++three) {
        				char mapping[26];
		        		bool isValid = true;
			        	for (int j = 0; j < 26; ++j) {
			        		mapping[j] = '?';	
			        	}
			        	//one
		        		for (int j = 0; j < bag[0][one].size(); ++j) {
		        			if(mapping[original[0][j]-'A'] == '?') {
		        				mapping[original[0][j]-'A'] = bag[0][one][j];
		        			}
		        			else {
		        				if(mapping[original[0][j]-'A'] != bag[0][one][j]) {
		        					isValid = false;
		        					break;
		        				}
		        			}
		        		}
		        		if(!isValid) break;
		        		//two
		        		for (int j = 0; j < bag[1][two].size(); ++j) {
		        			if(mapping[original[1][j]-'A'] == '?') {
		        				mapping[original[1][j]-'A'] = bag[1][two][j];
		        			}
		        			else {
		        				if(mapping[original[1][j]-'A'] != bag[1][two][j]) {
		        					isValid = false;
		        					break;
		        				}
		        			}
		        		}
		        		if(!isValid) break;
		        		//three
		        		for (int j = 0; j < bag[2][three].size(); ++j) {
		        			if(mapping[original[2][j]-'A'] == '?') {
		        				mapping[original[2][j]-'A'] = bag[2][three][j];
		        			}
		        			else {
		        				if(mapping[original[2][j]-'A'] != bag[2][three][j]) {
		        					isValid = false;
		        					break;
		        				}
		        			}
		        		}
		        		if(isValid) ans++;
        			}
        		}
        	}
        }
        if(n == 4) {
        	for (int one = 0; one < bag[0].size(); ++one) {
        		for (int two = 0; two < bag[1].size(); ++two) {
        			for (int three = 0; three < bag[2].size(); ++three) {
        				for (int four = 0; four < bag[3].size(); ++four) {
        					// printf("here\n");
        					char mapping[26];
			        		bool isValid = true;
				        	for (int j = 0; j < 26; ++j) {
				        		mapping[j] = '?';	
				        	}
				        	//one
			        		for (int j = 0; j < bag[0][one].size(); ++j) {
			        			if(mapping[original[0][j]-'A'] == '?') {
			        				mapping[original[0][j]-'A'] = bag[0][one][j];
			        			}
			        			else {
			        				if(mapping[original[0][j]-'A'] != bag[0][one][j]) {
			        					isValid = false;
			        					break;
			        				}
			        			}
			        		}
			        		if(!isValid) break;
			        		//two
			        		for (int j = 0; j < bag[1][two].size(); ++j) {
			        			if(mapping[original[1][j]-'A'] == '?') {
			        				mapping[original[1][j]-'A'] = bag[1][two][j];
			        			}
			        			else {
			        				if(mapping[original[1][j]-'A'] != bag[1][two][j]) {
			        					isValid = false;
			        					break;
			        				}
			        			}
			        		}
			        		if(!isValid) break;
			        		//three
			        		for (int j = 0; j < bag[2][three].size(); ++j) {
			        			if(mapping[original[2][j]-'A'] == '?') {
			        				mapping[original[2][j]-'A'] = bag[2][three][j];
			        			}
			        			else {
			        				if(mapping[original[2][j]-'A'] != bag[2][three][j]) {
			        					isValid = false;
			        					break;
			        				}
			        			}
			        		}
			        		if(!isValid) break;
			        		//three
			        		for (int j = 0; j < bag[3][four].size(); ++j) {
			        			if(mapping[original[3][j]-'A'] == '?') {
			        				mapping[original[3][j]-'A'] = bag[3][four][j];
			        			}
			        			else {
			        				if(mapping[original[3][j]-'A'] != bag[3][four][j]) {
			        					isValid = false;
			        					break;
			        				}
			        			}
			        		}
			        		if(isValid) ans++;		
        				}		
        			}
        		}
        	}
        }
        cout << ans << endl;
    }
    return 0;
}