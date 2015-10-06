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


LL table[105][105];
LL x,xx,y,yy,n,answer;

// main code begins now

int main()
{
    cin >> n ;
    for (LL i = 0; i < n; ++i) {
    	scanf("%I64d %I64d %I64d %I64d",&x,&y,&xx,&yy);
    	// cin >> x1 >> y1 >> x2 >> y2;
    	for (LL j = y; j <= yy; ++j) {
    		for (LL k = x; k <= xx; ++k) {
    			table[j][k]++;
    		}
    	}
    }
    for (LL j = 1; j <= 100; ++j) {
		for (LL k = 1; k <= 100; ++k) {
			answer += table[j][k];
		}
    }
    cout << answer << endl;
    return 0;
}