#include <bits/stdc++.h>

using namespace std;



#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;



int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int a[30] = {0};
    	string inp;
    	cin >> inp;
    	for (int i = 0; i < inp.size(); ++i) {
    		a[inp[i]-'A']++;
    	}
    	if(inp.size() < 8) {
    		printf("NO\n");
    	}
    	else if(inp.size() == 9) {
    		if(a['L'-'A'] == 2 && a['T'-'A'] == 2 && a['I'-'A'] == 2 && a['E'-'A'] == 1 && a['M'-'A'] == 2) printf("YES\n");
    		else printf("NO\n");
    	}
    	else {
    		if(a['L'-'A'] >= 2 && a['T'-'A'] >= 2 && a['I'-'A'] >= 2 && a['E'-'A'] >= 2 && a['M'-'A'] >= 2) printf("YES\n");
    		else printf("NO\n");
    	}
    }
    return 0;
}