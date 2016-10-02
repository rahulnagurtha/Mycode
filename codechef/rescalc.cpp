#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif

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
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int score[105] = {0};
        int n;
        int num;
        int type;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
        	int cnt[7] = {0};
        	VI Q;
        	cin >> num;
        	for (int j = 0; j < num; ++j) {
        		cin >> type;
        		cnt[type]++;
        	}
        	score[i] = num;
        	for (int j = 1; j <= 6; ++j) {
        		Q.pb(cnt[j]);
        	}
        	sort(Q.begin(),Q.end());
        	int maxpossible = 0;
        	int four,five,six;
        	//number of 4
        	for (int j = 0; j <= Q[2]; ++j) {
        		VI Q1;
        		Q1 = Q;
        		four = j;
        		for (int k = 2; k < Q1.size(); ++k) {
        			Q1[k] -= j;
        		}
        		sort(Q1.begin(),Q1.end());
        		//number of 5
        		for (int k = 0; k <= Q1[1]; ++k) {
        			five = 2*k;
        			VI Q2;
        			Q2 = Q1;
        			for (int l = 1; l < Q2.size(); ++l) {
        				Q2[l] -= k;
        			}
        			sort(Q2.begin(),Q2.end());
        			six = 4*Q2[0];
        			maxpossible = max(maxpossible,four + five + six);
        		}
        	}
        	score[i] += maxpossible;
        }
        int maxScore = 0;
        int maxCount = 0;
        int maxScoreIdx;
        for (int i = 1; i <= n; ++i) {
        	maxScore = max(score[i],maxScore);
        }
        for (int i = 1; i <= n; ++i) {
        	if(score[i] == maxScore) maxCount++;
        }
        if(maxCount > 1) printf("tie\n");
        else {
        	for (int i = 1; i <= n; ++i) {
        		if(maxScore == score[i]) {
        			maxScoreIdx = i;
        			break;
        		}
        	}
        	if(maxScoreIdx == 1) printf("chef\n");
        	else printf("%d\n",maxScoreIdx);
        }
    }
    return 0;
}