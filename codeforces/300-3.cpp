#include <bits/stdc++.h>

using namespace std;


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

LL n,m,d,h,ld,lh,answer,tmp,flag,diff,hdiff;


void process() {
	diff = d - ld;
	hdiff = abs(h - lh);
	if( hdiff > diff) {
		flag = 1;
		return;
	}
	if( h == lh ) {
		answer = max(answer,h + diff/2);
	}
	else if( h < lh ) {
		answer = max(answer,lh + (diff-hdiff)/2);
	}
	else {
		answer = max(answer,h + (diff-hdiff)/2);
	}
}


// main code begins now

int main()
{
    cin >> n >> m;
    cin >> d >> h;
    ld = d;
    lh = h;
    answer = d + h - 1;
    for (int i = 1; i < m; ++i) {
    	cin >> d >> h;
    	if(flag == 0) {
    		process();
    		ld = d;
    		lh = h;
    	}
    }
    answer = max(answer,h + n - d);
    if(flag == 1) printf("IMPOSSIBLE\n");
    else printf("%I64d\n",answer);
    return 0;
}