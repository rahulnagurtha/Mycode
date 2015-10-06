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





int gcd(int a,int b) {
	if(a<b) swap(a,b);
	int temp;
	while(b!=0) {
		temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}


struct tree {
	int gd;
};

tree part[500005];

int arr[100005];

/*
****the indexing can be from [0,n-1] or [1,n]
****based on the type pass the necessary arguments
****for example if [0,n-1] update(1,x,0,n-1,y) 
				if [1,n] update(1,x,1,n,y);
*/



// Build and init tree with array [i,j]

void build(int node,int i,int j) {
// printf("enter\n");
	if(i>j) return;		 // invalid range to build
	if(i==j) {				
		// printf("setting node[%d]=%d\n",node,arr[i]);		
		part[node].gd=arr[i];			// Leaf nodes initialisation
		return;
	}

	build(node*2,i,(i+j)/2);	// Init left child
	build(node*2+1,1+(i+j)/2,j);	// Init right child

	//update the node based on the values of left and right nodes
	// printf("finding gcd\n");
	part[node].gd=gcd(part[node*2].gd,part[1+node*2].gd);
	// printf("setting node[%d]=%d\n",node,part[node].gd);
	// printf("gcd complete\n");
	return;
}




/**
 * Query tree to get min element value within range [i, j]
 */

int query_min(int node,int a,int b,int i,int j) {

	if(a > b || a > j || b < i) return 2147483645;	//invalid segment
	if(a >= i && b <= j) return part[node].gd;		// Current segment is totally within range [i, j]
	
	int q1,q2;

	q1=query_min(node*2, a, (a+b)/2, i, j);	//query the left child
	q2=query_min(1+node*2, 1+(a+b)/2, b, i, j); //query the right child
	if(q1==2147483645) q1=q2;
	if(q2==2147483645) q2=q1;
	int res = gcd(q1, q2); //return the final result based on left and right child
	return res;
}


// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int n,q,l,r,ans1,ans2;
    	cin >> n >> q ;
    	for (int i = 1; i <= n; ++i) {
    		cin >> arr[i] ;
    	}
    	build(1,1,n);
    	for (int i = 0; i < q; ++i) {
    		cin >> l >> r ;
    		if(l==1) {
    			ans1=query_min(1,1,n,r+1,n);
    			cout << ans1 << endl ;
    			continue;
    		}
    		if(r==n) {
    			ans1=query_min(1,1,n,1,l-1);
    			cout << ans1 << endl ;
    			continue;
    		}
    		ans1=query_min(1,1,n,1,l-1);
    		ans2=query_min(1,1,n,r+1,n);
    		ans1=gcd(ans1,ans2);
    		cout << ans1 << endl ;
    	}
    }
    return 0;
}