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




typedef long long int ll;



struct tree {
    ll lazy;
    ll sum;
};

tree part[500001];


/*
****the indexing can be from [0,n-1] or [1,n]
****based on the type pass the necessary arguments
****for example if [0,n-1] update(1,x,0,n-1,y) 
                if [1,n] update(1,x,1,n,y);
*/



// Build and init tree with array [i,j]

void build(int node,int i,int j) {

    if(i>j) return;         // invalid range to build
    if(i==j) {                        
        part[node].sum=0;
        part[node].lazy=0;
        return;
    }

    build(node*2,i,(i+j)/2);    // Init left child
    build(node*2+1,1+(i+j)/2,j);    // Init right child

    //update the node based on the values of left and right nodes
    part[node].sum=part[node*2].sum+part[1+node*2].sum;
    part[node].lazy=0;
    return;
}


/**
 * Query tree to get sum within range [i, j]
 */
ll query_sum(int node,int a,int b,int i,int j) {
    if(a > b || a > j || b < i) return 0;    //invalid segment
    
    if(part[node].lazy != 0) { // This node needs to be updated
        if(part[node].lazy%2 != 0) part[node].sum = (ll)(b-a+1) - part[node].sum; // Update it
 
        if(a != b && part[node].lazy%2 != 0) {
            part[node*2].lazy += part[node].lazy; // Mark child as lazy
            part[node*2+1].lazy += part[node].lazy; // Mark child as lazy
        }
        part[node].lazy = 0; // Reset it
    }


    if(a >= i && b <= j) return part[node].sum;    //Current segment is totally within range [i, j]

    ll q1,q2;

    q1=query_sum(node*2, a, (a+b)/2, i, j);    //query left child
    q2=query_sum(1+node*2, 1+(a+b)/2, b, i, j); //query right child
    
    // printf("adding %lld,%lld\n",q1,q2);
    ll res = q1+q2;    //return the final result based on left and right child
    
    return res;
}




/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

    if(part[node].lazy != 0) { // This node needs to be updated

        if(part[node].lazy%2 != 0) part[node].sum = (ll)(b-a+1)-part[node].sum; // Update it

        if(a != b && part[node].lazy%2 != 0) {
            part[node*2].lazy += part[node].lazy; // Mark child as lazy
            part[node*2+1].lazy += part[node].lazy; // Mark child as lazy
        }
        part[node].lazy = 0; // Reset it
    }

    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    
    if(a >= i && b <= j) { // Segment is fully within range
        part[node].sum = (ll)(b-a+1)-part[node].sum;

        if(a != b) { // Not leaf node
            part[node*2].lazy += (ll)value;
            part[node*2+1].lazy += (ll)value;
        }
        return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
    part[node].sum = part[node*2].sum + part[1+node*2].sum; // Updating root with max value
}




// main code begins now

int main()
{
    // freopen("in.txt", "r", stdin);
	int n,q,A,B,type;
	cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		cin >> type >> A >> B ;
		if(type == 0) {
			// printf("updating the status between %d %d\n",A,B);
			update_tree(1,1,n,A+1,B+1,1);
		}
		else {
			// printf("printing the answer between %d %d\n",A,B);
			printf("%lld\n",query_sum(1,1,n,A+1,B+1));
		}
	}
    return 0;
}