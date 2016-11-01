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
    int t;
    int testcase = 1;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
        cout << "Case #" << testcase << ": ";
        int vocCnt[405][26];
        int vocSize[405];
        int cypherCnt[4005][26];
        int dp[4005];
        int v,s;
        fill(vocCnt,0);
        string tmp,cypher;
        cin >> v >> s;
        for (int i = 0; i < v; ++i) {
        	cin >> tmp;
        	vocSize[i] = tmp.size();
        	for (int j = 0; j < tmp.size(); ++j) {
        		vocCnt[i][tmp[j] - 'a']++;
        	}
        }
        for (int i = 0; i < s; ++i) {
        	cin >> cypher;
        	fill(dp,0);
        	fill(cypherCnt,0);
        	for (int j = 0; j < cypher.size(); ++j) {
        		for (int k = 0; k < 26; ++k) {
        			cypherCnt[j][k] = ( j > 0 ? cypherCnt[j-1][k] : 0);
        		}
        		cypherCnt[j][cypher[j] - 'a']++;
        	}
        	//fill dp
        	dp[cypher.size()] = 1;
        	for (int x = cypher.size() - 1; x >= 0; --x) {
        		for (int y = 0; y < v; ++y) {
        			int starting = x;
        			int ending = x + vocSize[y] - 1;
        			if(ending > cypher.size() - 1) continue;
        			bool allMatched = true;
        			for (int ctr = 0; ctr < 26; ++ctr) {
        				int src = vocCnt[y][ctr];
        				int target = cypherCnt[ending][ctr];
        				if(starting > 0) target -= cypherCnt[starting-1][ctr];
        				if(src != target)
        					allMatched = false;
        			}
        			if(allMatched) {
        				dp[x] += dp[ending + 1];
        				dp[x] %= MOD;
        			}
        		}
        	}
        	cout << dp[0] << " ";
        }
        cout << endl;
        testcase++;
    }
    return 0;
}