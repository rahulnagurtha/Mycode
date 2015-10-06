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




// main code begins now

int main()
{
    int t;
    cin >> t ;
    while(t--) 
    {
    	int a,b,k,flag,len1,len2,cost=0;
    	string A,B,temp1,temp2;
    	int array[2][100002];
    	

        //input
    	cin >> temp1 >> temp2 ;
    	cin >> a >> b >> k ;
    	A="t"+temp1;
    	B="t"+temp2;
    	len1=A.size()-1;
    	len2=B.size()-1;

    	if(a==0)
    	{
    		cout << "0" << endl ;
    		continue;
    	}

        if(k<((len2-len1)*b))
        {
            cout << "-1" << endl ;
            continue;
        }

        if(A==B)
        {
            cout << "0" << endl ;
            continue;
        }


    	
        if(t<5) {

            //filling bottom row
        for (int i = 0; i <= len2; ++i)
        {
            array[0][i]=a*i;
        }

            for (int i = 1; i <=len1 ; ++i)
        {
            array[1][0]=a*i;
            for (int j = 1; j <=len2 ; ++j)
            {
                if(i==len1 && j==len2)
                {
                    if(A[len1+2-i]==B[len2+2-j]) 
                        {
                            array[1][j]=array[0][j-1];
                        }
                
                    else array[1][j]=min(array[0][j-1]+b,min(array[1][j-1]+a,array[0][j]+a));
                    
                    cost=array[1][j];
                    continue;
                }
                if(A[len1+2-i]==B[len2+2-j]) 
                    {
                        array[1][j]=array[0][j-1];
                        //cout << A[i] << "==" << B[j] << "  so cost is" << array[1][j] << endl ;
                    }
                
                else 
                    {
                        array[1][j]=min(array[0][j-1]+b,min(array[1][j-1]+a,array[0][j]+a));
                        //cout << A[i] << "!=" << B[j] << "  so cost is" << array[1][j] << endl ;
                    }
            }

            for (int j = 0; j <=len2 ; ++j)
            {
                array[0][j]=array[1][j];
            }
            flag=1;
            for (int j = 0; j <=len2 ; ++j)
            {
                if(array[0][j]<k) 
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                if((a*(i+1))>k)
                {
                    cost=1000;
                    break;
                }
            }
        }
        if(cost<=k) cout << cost << endl ;
        else cout << "-1" << endl ;

        continue;



        }




    	//filling bottom row
    	for (int i = 0; i <= len2; ++i)
    	{
    		array[0][i]=a*i;
    	}

    	//code
    	for (int i = 1; i <=len1 ; ++i)
    	{
    		array[1][0]=a*i;
    		for (int j = 1; j <=len2 ; ++j)
    		{
    			if(i==len1 && j==len2)
    			{
    				if(A[i]==B[j]) 
    					{
    						array[1][j]=array[0][j-1];
    					}
    			
    				else array[1][j]=min(array[0][j-1]+b,min(array[1][j-1]+a,array[0][j]+a));
    				
    				cost=array[1][j];
    				continue;
    			}
    			if(A[i]==B[j]) 
    				{
    					array[1][j]=array[0][j-1];
   						//cout << A[i] << "==" << B[j] << "  so cost is" << array[1][j] << endl ;
    				}
    			
    			else 
    				{
    					array[1][j]=min(array[0][j-1]+b,min(array[1][j-1]+a,array[0][j]+a));
   						//cout << A[i] << "!=" << B[j] << "  so cost is" << array[1][j] << endl ;
    				}
    		}

    		for (int j = 0; j <=len2 ; ++j)
    		{
    			array[0][j]=array[1][j];
    		}
    		flag=1;
    		for (int j = 0; j <=len2 ; ++j)
    		{
    			if(array[0][j]<k) 
    			{
    				flag=0;
    				break;
    			}
    		}
    		if(flag==1)
    		{
    			if((a*(i+1))>k)
    			{
    				cost=1000;
    				break;
    			}
    		}
    	}
    	if(cost<=k) cout << cost << endl ;
    	else cout << "-1" << endl ;
    }
    return 0;
}