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



typedef long long int LL;

struct tree {
	LL ma;
};

tree part[1000005];

LL arr[200005];

/*
****the indexing can be from [0,n-1] or [1,n]
****based on the type pass the necessary arguments
****for example if [0,n-1] update(1,x,0,n-1,y) 
				if [1,n] update(1,x,1,n,y);
*/



// Build and init tree with array [i,j]

void build(LL node,LL i,LL j) {

	if(i>j) return;		 // invalid range to build
	if(i==j) {						
		part[node].ma=arr[i];
		return;
	}

	build(node*2,i,(i+j)/2);	// Init left child
	build(node*2+1,1+(i+j)/2,j);	// Init right child

	//update the node based on the values of left and right nodes
	part[node].ma=max(part[node*2].ma,part[1+node*2].ma);
	return;
}


/**
 * Query tree to get max element value within range [i, j]
 */

LL query_max(LL node,LL a,LL b,LL i,LL j) {

	if(a > b || a > j || b < i) return -2147483645;	//invalid segment
	
	if(a >= i && b <= j) return part[node].ma;	// Current segment is totally within range [i, j]

	LL q1,q2;

	q1=query_max(node*2, a, (a+b)/2, i, j);	//query the left child
	q2=query_max(1+node*2, 1+(a+b)/2, b, i, j);	//query the right child
	
	LL res = max(q1, q2);	//return the final result based on left and right child
	
	return res;
}



// main code begins now

int main()
{
    LL n,t,c,cnt = 0;
    cin >> n >> t >> c;
    for (LL i = 1; i <= n; ++i) {
    	cin >> arr[i];
    }
    build(1,1,n);
    for (LL i = 1; i <= n+1-c; ++i) {
    	if(query_max(1,1,n,i,i+c-1) <= t) cnt++;
    }
    cout << cnt << endl;
    return 0;
}