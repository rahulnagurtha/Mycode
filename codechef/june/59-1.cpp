#include <bits/stdc++.h>

using namespace std;


#define si(i) 					scanf("%d",&i)
#define slli(i) 				scanf("%lld",&i)

#define pi(i) 					printf("%d\n",i)
#define plli(i) 				printf("%lld\n",i)

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



// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	LL n,k,arr[1005],summ;
    	cin >> n >> k;
    	for (int i = 1; i <= n; ++i) {
    		cin >> arr[i];
    	}
    	summ = 0;
    	for (int i = 1; i <= n; ++i) {
    		summ += arr[i];
    	}
    	if((summ+1)%2 == 0 || k > 1) printf("even\n");
    	else printf("odd\n");
    }
    return 0;
}