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
	LL high;
	LL lhigh;
	LL rhigh;
	LL sum;
};

tree part[500001];

LL arr[100001];


void build(LL node,LL i,LL j) {

	if(i>j) return;		 // invalid range to build
	if(i==j) {				
		part[node].lhigh = arr[i];			// Leaf nodes initialisation
		part[node].rhigh = arr[i];
		part[node].high = arr[i];
		part[node].sum = arr[i];
		return;
	}

	build(node*2,i,(i+j)/2);	// Init left child
	build(node*2+1,1+(i+j)/2,j);	// Init right child

	//update the sum
	part[node].sum=part[node*2].sum+part[1+node*2].sum;
	//update lhigh
	part[node].lhigh = max(part[2*node].lhigh,part[2*node].sum + part[1+2*node].lhigh);
	//update rhigh
	part[node].rhigh = max(part[1+2*node].rhigh,part[1+2*node].sum + part[2*node].rhigh);
	//update high
	part[node].high = max(part[2*node].rhigh + part[1+2*node].lhigh,max(part[2*node].high,part[1+2*node].high));
	return;
}

struct tree query_sum(LL node,LL a,LL b,LL i,LL j) {
	struct tree dummy;
	if(a > b || a > j || b < i) {
		dummy.high = -99999999999;
		dummy.lhigh = -99999999999;
		dummy.rhigh = -99999999999;
		dummy.sum = -99999999999;
		return dummy;	//invalid segment
	}
	if(a >= i && b <= j) {
		dummy.high = part[node].high;
		dummy.lhigh = part[node].lhigh;
		dummy.rhigh = part[node].rhigh;
		dummy.sum = part[node].sum;
		return dummy;	//Current segment is totally within range [i, j]
	}
	struct tree q1,q2;

	q1=query_sum(node*2, a, (a+b)/2, i, j);	//query left child
	q2=query_sum(1+node*2, 1+(a+b)/2, b, i, j); //query right child
	
	struct tree res;
	if(q1.high != -99999999999 && q2.high != -99999999999) {
		res.high = max(q1.high,max(q2.high,q1.rhigh+q2.lhigh));
		res.lhigh = max(q1.lhigh,q1.sum+q2.lhigh);
		res.rhigh = max(q2.rhigh,q2.sum+q1.rhigh);
		res.sum = q1.sum + q2.sum;
	}
	else if(q1.high == -99999999999) {
		res = q2;
	}
	else res = q1;
	
	return res;
}



// main code begins now

int main()
{
    LL n,m,a,b,tmp;
    cin >> n ;
    for (LL i = 1; i <= n; ++i) {
    	cin >> arr[i] ;
    }
    build(1,1,n);
    cin >> m ;
    for (LL i = 0; i < m; ++i) {
    	cin >> a >> b ;
    	tmp = query_sum(1,1,n,a,b).high;
    	cout << tmp << endl;
    }
    return 0;
}