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




inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;
    while (c < 33)
        c = getchar_unlocked();
    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
    str[i] = '\0';
}
 
 
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}


long long int let[4][1000006];
long long int data[12][1000006];


// main code begins now

int main()
{
    int t,l,r,check;
    long long int ans;
    char test,a,b,special[1000005];
	fastRead_string(special);
    // scanf("%s",special);
    if (special[0]=='c') {
        let[0][0]=1;
    }
    else if (special[0]=='h') {
        let[1][0]=1;
    }
    else if (special[0]=='e') {
        let[2][0]=1;
    }
    else {
        let[3][0]=1;
    }
	check=strlen(special);
    for (int i = 1; i < check; ++i) {
    	if(special[i]=='c') {
    		let[0][i]=let[0][i-1]+1;
    		let[1][i]=let[1][i-1];
    		let[2][i]=let[2][i-1];
    		let[3][i]=let[3][i-1];

    		data[3][i]=data[3][i-1]+let[1][i-1];
    		data[6][i]=data[6][i-1]+let[2][i-1];
    		data[9][i]=data[9][i-1]+let[3][i-1];
            data[0][i]=data[0][i-1];
            data[7][i]=data[7][i-1];
            data[10][i]=data[10][i-1];
            data[1][i]=data[1][i-1];
            data[4][i]=data[4][i-1];
            data[11][i]=data[11][i-1];
            data[2][i]=data[2][i-1];
            data[5][i]=data[5][i-1];
            data[8][i]=data[8][i-1];
    	}
    	else if(special[i]=='h') {
    		let[0][i]=let[0][i-1];
    		let[1][i]=let[1][i-1]+1;
    		let[2][i]=let[2][i-1];
    		let[3][i]=let[3][i-1];

            data[0][i]=data[0][i-1]+let[0][i-1];
            data[7][i]=data[7][i-1]+let[2][i-1];
            data[10][i]=data[10][i-1]+let[3][i-1];
            data[3][i]=data[3][i-1];
            data[6][i]=data[6][i-1];
            data[9][i]=data[9][i-1];
            data[1][i]=data[1][i-1];
            data[4][i]=data[4][i-1];
            data[11][i]=data[11][i-1];
            data[2][i]=data[2][i-1];
            data[5][i]=data[5][i-1];
            data[8][i]=data[8][i-1];
        }
    	else if(special[i]=='e') {
    		let[0][i]=let[0][i-1];
    		let[1][i]=let[1][i-1];
    		let[2][i]=let[2][i-1]+1;
    		let[3][i]=let[3][i-1];
    		
            data[1][i]=data[1][i-1]+let[0][i-1];
            data[4][i]=data[4][i-1]+let[1][i-1];
            data[11][i]=data[11][i-1]+let[3][i-1];
            data[3][i]=data[3][i-1];
            data[6][i]=data[6][i-1];
            data[9][i]=data[9][i-1];
            data[0][i]=data[0][i-1];
            data[7][i]=data[7][i-1];
            data[10][i]=data[10][i-1];
            data[2][i]=data[2][i-1];
            data[5][i]=data[5][i-1];
            data[8][i]=data[8][i-1];
        }
    	else {
    		let[0][i]=let[0][i-1];
    		let[1][i]=let[1][i-1];
    		let[2][i]=let[2][i-1];
    		let[3][i]=let[3][i-1]+1;
    	    
            data[2][i]=data[2][i-1]+let[0][i-1];
            data[5][i]=data[5][i-1]+let[1][i-1];
            data[8][i]=data[8][i-1]+let[2][i-1];
            data[3][i]=data[3][i-1];
            data[6][i]=data[6][i-1];
            data[9][i]=data[9][i-1];
            data[0][i]=data[0][i-1];
            data[7][i]=data[7][i-1];
            data[10][i]=data[10][i-1];
            data[1][i]=data[1][i-1];
            data[4][i]=data[4][i-1];
            data[11][i]=data[11][i-1];
        }
        // printf("after %d :\n",i);
        // cout << "c-" << let[0][i] << endl ;
        // cout << "h-" << let[1][i] << endl ;
        // cout << "e-" << let[2][i] << endl ;
        // cout << "f-" << let[3][i] << endl ;
        // cout << "ch-" << data[0][i] << endl ;
        // cout << "ce-" << data[1][i] << endl ;
        // cout << "cf-" << data[2][i] << endl ;
        // cout << "hc-" << data[3][i] << endl ;
        // cout << "he-" << data[4][i] << endl ;
        // cout << "hf-" << data[5][i] << endl ;
        // cout << "ec-" << data[6][i] << endl ;
        // cout << "eh-" << data[7][i] << endl ;
        // cout << "ef-" << data[8][i] << endl ;
        // cout << "fc-" << data[9][i] << endl ;
        // cout << "fh-" << data[10][i] << endl ;
        // cout << "fe-" << data[11][i] << endl ;
    }
    // scanf("%d",&t);
    // cin >> t ;
    fastRead_int(t);
    // getchar();
    while(t--) {
        scanf("%c %c %d %d",&a,&b);
        // scanf("%c %c",&a,&b);
    	// a=getchar();
        // getchar();
        // b=getchar();
        // fastRead_int(l);
        // fastRead_int(r);
        // printf("%d,%d\n",l,r);
    	// cout << tbsrchd << endl ;
    	if(l==1) {
            if(a=='c' && b=='h') {
                ans=data[0][r-1];
            }
            else if(a=='c' && b=='e') {
                ans=data[1][r-1];
            }
            else if(a=='c' && b=='f') {
                ans=data[2][r-1];
            }
            else if(a=='h' && b=='c') {
                ans=data[3][r-1];
            }
            else if(a=='h' && b=='e') {
                ans=data[4][r-1];
            }
            else if(a=='h' && b=='f') {
                ans=data[5][r-1];
            }
            else if(a=='e' && b=='c') {
                ans=data[6][r-1];
            }
            else if(a=='e' && b=='h') {
                ans=data[7][r-1];
            }
            else if(a=='e' && b=='f') {
                ans=data[8][r-1];
            }
            else if(a=='f' && b=='c') {
                ans=data[9][r-1];
            }
            else if(a=='f' && b=='h') {
                ans=data[10][r-1];
            }
            else {
                ans=data[11][r-1];
            }
        }
        else if(a=='c' && b=='h') {
            ans=data[0][r-1]-data[0][l-2]-(let[0][l-2]*(let[1][r-1]-let[1][l-2]) );
        }
        else if(a=='c' && b=='e') {
            ans=data[1][r-1]-data[1][l-2]-(let[0][l-2]*(let[2][r-1]-let[2][l-2]) );
        }
        else if(a=='c' && b=='f') {
            ans=data[2][r-1]-data[2][l-2]-(let[0][l-2]*(let[3][r-1]-let[3][l-2]) );
        }
        else if(a=='h' && b=='c') {
            ans=data[3][r-1]-data[3][l-2]-(let[1][l-2]*(let[0][r-1]-let[0][l-2]) );
        }
        else if(a=='h' && b=='e') {
            ans=data[4][r-1]-data[4][l-2]-(let[1][l-2]*(let[2][r-1]-let[2][l-2]) );
        }
        else if(a=='h' && b=='f') {
            ans=data[5][r-1]-data[5][l-2]-(let[1][l-2]*(let[3][r-1]-let[3][l-2]) );
        }
        else if(a=='e' && b=='c') {
            ans=data[6][r-1]-data[6][l-2]-(let[2][l-2]*(let[0][r-1]-let[0][l-2]) );
        }
        else if(a=='e' && b=='h') {
            ans=data[7][r-1]-data[7][l-2]-(let[2][l-2]*(let[1][r-1]-let[1][l-2]) );
        }
        else if(a=='e' && b=='f') {
            ans=data[8][r-1]-data[8][l-2]-(let[2][l-2]*(let[3][r-1]-let[3][l-2]) );
        }
        else if(a=='f' && b=='c') {
            ans=data[9][r-1]-data[9][l-2]-(let[3][l-2]*(let[0][r-1]-let[0][l-2]) );
        }
        else if(a=='f' && b=='h') {
            ans=data[10][r-1]-data[10][l-2]-(let[3][l-2]*(let[1][r-1]-let[1][l-2]) );
        }
        else {
            ans=data[11][r-1]-data[11][l-2]-(let[3][l-2]*(let[2][r-1]-let[2][l-2]) );
        }
    	// printf("%lld\n",ans);
    	cout << ans << endl ;
        // getchar();
    }
    return 0;
}