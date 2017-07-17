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



int ans;


inline void Refresh() {
    ans = 0;
}


int main()
{
    int t;
    int testcase = 1;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
        VI A;
        deque<int> Q;
        int n,tmp;
        cin >> n;
        for (int i = 0; i < n; ++i) {
        	cin >> tmp;
        	A.pb(tmp);
        }
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); ++i) {
        	Q.pb(A[i]);
        }
        while(Q.size() > 0) {
        	int ctr = 0;
        	int curTop = Q.back();
        	int required = ceil(50,curTop) - 1;
        	Q.pop_back();
        	while(ctr < required && Q.size() > 0) {
        		Q.pop_front();
        		ctr++;
        	}
        	if(ctr == required) ans++;
        }
        // print answer;
        cout << "Case #" << testcase << ": ";
        cout << ans << endl;
        testcase++;
    }
    return 0;
}