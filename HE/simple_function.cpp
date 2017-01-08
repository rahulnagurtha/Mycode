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


int A[1005][10];
int B[1005][10];

inline void Refresh() {
    fill(A,0);
    fill(B,0);
    return;
}


int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    si(t);
    while(t--) {
    	Refresh();
    	int n1,n2;
    	string tmp;
    	cin >> n1 >> n2;
    	for (int i = 1; i <= n1; ++i) {
    		cin >> tmp;
    		for (int j = 0; j < tmp.size(); ++j) {
    			A[i][tmp[j] - '0'] = 1;
    		}
    		A[i][0] = 1;
    	}
    	for (int i = 1; i <= n2; ++i) {
    		cin >> tmp;
    		for (int j = 0; j < tmp.size(); ++j) {
    			B[i][tmp[j] - '0'] = 1;
    		}
    		B[i][0] = 1;
    	}
    	int total = n1*n2;
    	int goodPairs = 0;
    	for (int i = 1; i <= n1; ++i) {
    		for (int j = 1; j <= n2; ++j) {
    			int foundInBoth;
    			for (int k = 9; k >= 0; --k) {
    				if(A[i][k] == 1 && B[j][k] == 1) {
    					foundInBoth = k;
    					break;
    				}
    			}
    			if(foundInBoth % 2 == 0) goodPairs++;
    		}
    	}
    	cout << fixed << setprecision(3) << ((float)goodPairs)/total << endl;

    }
    return 0;
}