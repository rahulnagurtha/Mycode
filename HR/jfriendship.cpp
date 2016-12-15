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

#define rep(i,a,b)              for(int i = (a); (i) <= (b); (i)++)
#define per(i,a,b)              for(int i = (a); (i) >= (b); (i)--)
#define reps(i,a,b,s)           for(int i = (a); (i) <= (b); i += (s))
#define pers(i,a,b,s)           for(int i = (a); (i) >= (b); i -= (s))

#define SYNC                    ios_base::sync_with_stdio(0)
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





inline void Refresh() {
    
}

int n;
string a;

int isSafe[2*N + 5];
bool visited[2*N+5];


int dfs(int cur) {
	if(cur < 0 || cur >= n) return 0;
	if(visited[cur]) return isSafe[cur];
	visited[cur] = true;
	if(a[cur] == '<') {
		isSafe[cur] = dfs(cur-1);
	}
	else {
		isSafe[cur] = dfs(cur+1);
	}
	return isSafe[cur];
}

int main()
{
    
    cin >> n;
    cin >> a;
    for (int i = 0; i < 2*N; ++i) {
    	isSafe[i] = 1;
    }
    fill(visited,false);
    for (int i = 0; i < n; ++i) {
    	if(!visited[i]) {
    		dfs(i);
    	}
    }
    int ans = 0;
    for (int i = 0; i < n ; ++i) {
    	if(isSafe[i] == 0) {
    		ans++;
    	}
    }
    if(ans != 0) cout << ans << endl;
    else cout << "Friendship" << endl;
    return 0;
}