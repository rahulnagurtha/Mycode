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
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF 					INT_MAX
#define N                     	100007


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
	int n,m,tmp;
	vector<pair<int,PII> > aux;
	VI A;
	VI ans;
	cin >> n >> m;
	int final_matrix[1005][1005];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> tmp;
			A.pb(tmp);
			aux.pb(mp(i*j,mp(i,j)));
		}
	}
	sort(A.begin(), A.end());
	deque<int> Q;
	for (int i = 0; i < A.size(); ++i) {
		Q.pb(A[i]);
	}
	while(Q.size() > 0) {
		int lft = Q.front();
		Q.pop_front();
		while((lft > 1) && (Q.size() > 0)) {
			int delta = lft - 1;
			if((m - Q.back()) > delta) {
				Q.back() += delta;
			}
			else {
				ans.pb(m);
				delta = m - Q.back();
				Q.pop_back();
			}
			lft -= delta;
		}
		if(lft >= 1) ans.pb(lft);
	}
	sort(ans.begin(), ans.end());
	sort(aux.begin(), aux.end());
	for (int i = 0; i < ans.size(); ++i) {
		final_matrix[aux[i].SS.FF][aux[i].SS.SS] = ans[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << final_matrix[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}