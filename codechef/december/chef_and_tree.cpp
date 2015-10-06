#include <bits/stdc++.h>

using namespace std;



#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define tri(a,b,c)              mp(a,mp(b,c))
#define XX                      first
#define YY                      second.first
#define ZZ                      second.second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 				((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 				(a-(box(a,b))*b)
#define ceil(a,b) 				((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 				((a%b<0)?(((a%b)+b)%b):(a%b))


typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;


typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;



// main code begins now

int main()
{
    int t;
    cin >> t ;
    while(t--) {
    	bool a[100005];
    	fill(a,false);
    	int n,temp,count=0;
    	cin >> n ;
    	for (int i = 0; i < n ; ++i) {
    		cin >> temp ;
    		a[temp]=true;
    	}
    	for (int i = 1; i < 100001; ++i) {
    		if(a[i]==true) count++;
    	}
    	printf("%d\n",count+1);
    }
    return 0;
}