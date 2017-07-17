#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

#define forup(i,a,b)            for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b)            for(int i = (a); (i) > (b); --(i))
#define rep(i,a)                for(int i = 0; (i) < (a); ++(i))

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                       100007


typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};



int num[20][20];


int main()
{
	int ans = 0;
    forup(i,0,20) {
    	forup(j,0,20) {
    		cin >> num[i][j];
    	}
    }
    forup(i,0,20) {
    	forup(j,0,20) {
    		//down
    		if(i + 3 < 20) {
    			ans = max(ans,num[i][j]*num[i+1][j]*num[i+2][j]*num[i+3][j]);
    		}
    		//right
    		if(j + 3 < 20) {
    			ans = max(ans,num[i][j]*num[i][j+1]*num[i][j+2]*num[i][j+3]);
    		}

    		//diagonal down-right
    		if((j + 3 < 20) && (i + 3 < 20)) {
    			ans = max(ans,num[i][j]*num[i+1][j+1]*num[i+2][j+2]*num[i+3][j+3]);
    		}

    		//diagonal down-left
    		if((j - 3 >= 0) && (i + 3 < 20)) {
    			ans = max(ans,num[i][j]*num[i+1][j-1]*num[i+2][j-2]*num[i+3][j-3]);
    		}
    	}
    }
    cout << ans << endl;
    return 0;
}