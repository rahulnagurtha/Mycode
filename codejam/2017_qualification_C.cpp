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



int n,k;
VI configuration;



inline void Refresh() {
    configuration.clear();
}

void init() {
	configuration.resize(n+2);
	configuration[0] = 1;
	configuration[n + 1] = 1;
	return;
}

int main()
{
    int t;
    int testcase = 1;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
        cout << "Case #" << testcase << ": ";
        cin >> n >> k;
        init();
        int l,r;
        for (int i = 0; i < k; ++i) {
        	VI lft(n+2);
	        VI ryt(n+2);
	        int last;
	        for (int j = 0; j < configuration.size(); ++j) {
	        	if(configuration[j] == 1) last = j;
	        	lft[j] = max(0,j - last - 1);
	        }
	        for (int j = configuration.size() - 1; j >= 0; --j) {
	        	if(configuration[j] == 1) last = j;
	        	ryt[j] = max(0,last - j - 1);
	        }
	        int so_far = -1;
	        int maxVal = -1;
	        int selected;
	        for (int j = 0; j < configuration.size(); ++j) {
	        	if(configuration[j] == 1) continue;
	        	int curVal = min(lft[j],ryt[j]);
	        	if(curVal > so_far) {
	        		l = min(lft[j],ryt[j]);
	        		r = max(lft[j],ryt[j]);
	        		so_far = curVal;
	        		maxVal = max(lft[j],ryt[j]);
	        		selected = j;
	        	}
	        	else if(curVal == so_far) {
	        		if(max(lft[j],ryt[j]) > maxVal) {
	        			l = min(lft[j],ryt[j]);
		        		r = max(lft[j],ryt[j]);
		        		so_far = curVal;
		        		maxVal = max(lft[j],ryt[j]);
	        			selected = j;
	        		}
	        	}
	        }
	        configuration[selected] = 1;
	        // cout << configuration << endl;
        }
        cout << r << " " << l << endl;
        testcase++;
    }
    return 0;
}