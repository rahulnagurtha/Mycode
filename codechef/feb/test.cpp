#include <bits/stdc++.h>

using namespace std;



#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b)                ( (a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)) )
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a%b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;



// main code begins now

int main()
{
    VOLL a;
    LL n,temp1,temp2;
    cin >> n ;
    FOR(i,0,n) {
    	slli(temp1);
    	slli(temp2);
    	a.pb(mp(temp1,temp2));
    }
    sort(a.begin(),a.end());
    ps("after sorting:");
    REP(i,n) {
    	cout << a[i].FF << " " << a[i].SS << endl ;
    }
    return 0;
}