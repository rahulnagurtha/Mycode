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


int main()
{

	map<PII,int> ans;
	//one
	ans[mp(1,1)] = 1;
	ans[mp(1,2)] = 2;
	ans[mp(1,3)] = 2;
	ans[mp(1,4)] = 3;
	ans[mp(1,5)] = 4;
	//one
	ans[mp(2,1)] = 2;
	ans[mp(2,2)] = 4;
	ans[mp(2,3)] = 4;
	ans[mp(2,4)] = 6;
	ans[mp(2,5)] = 8;
	//one
	ans[mp(3,1)] = 2;
	ans[mp(3,2)] = 4;
	ans[mp(3,3)] = 6;
	ans[mp(3,4)] = 8;
	ans[mp(3,5)] = 10;
	//one
	ans[mp(4,1)] = 3;
	ans[mp(4,2)] = 6;
	ans[mp(4,3)] = 8;
	ans[mp(4,4)] = 11;
	ans[mp(4,5)] = 14;
	//one
	ans[mp(5,1)] = 4;
	ans[mp(5,2)] = 8;
	ans[mp(5,3)] = 10;
	ans[mp(5,4)] = 14;
	ans[mp(5,5)] = 17;
    int t;
    int testcase = 1;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
        cout << "Case #" << testcase << ": ";
        int r,c;
        int answer;
        cin >> r >> c;
        if(ans.find(mp(r,c)) != ans.end()) answer = ans[mp(r,c)];
        else answer = 0;
        cout << answer << endl;
        testcase++;
    }
    return 0;
}