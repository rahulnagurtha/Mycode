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


struct Node {
	int l,r;
	int originalIdx;
	int dupIdx;
};

class lftComparisonClass {
public:
    bool operator() (Node lft, Node ryt) {
        return lft.l < ryt.l;
    }
};

class rytComparisonClass {
public:
    bool operator() (Node lft, Node ryt) {
        return lft.r > ryt.r;
    }
};


priority_queue<Node, vector<Node>, lftComparisonClass> lftQ;
priority_queue<Node, vector<Node>, rytComparisonClass> rytQ;
int n,k;
vector<pair<PII,int> > passes;

int main()
{
	SYNC;
	int ans = 0;
	int starting,ending;
	int l,r;
	cin >> n >> k;
	starting = 1;
	ending = k;
	for (int i = 1; i <= n; ++i) {
		cin >> l >> r;
		passes.pb(mp(mp(l,r),i));
	}
	sort(passes.begin(), passes.end());
	for (int i = 1; i < k; ++i) {
		Node tmp;
		tmp.l = passes[i - 1].FF.FF;
		tmp.r = passes[i - 1].FF.SS;
		tmp.originalIdx = passes[i - 1].SS;
		tmp.dupIdx = i;
		lftQ.push(tmp);
		rytQ.push(tmp);
	}
	for (int i = k; i <= n; ++i) {
		//insert and query
		Node tmp;
		tmp.l = passes[i - 1].FF.FF;
		tmp.r = passes[i - 1].FF.SS;
		tmp.originalIdx = passes[i - 1].SS;
		tmp.dupIdx = i;
		lftQ.push(tmp);
		rytQ.push(tmp);
		//insertion over
		int lftMax = 0;
		int rytMin = 0;
		//lft
		while(lftQ.top().dupIdx <= (i - k)) {
			lftQ.pop();
		}
		//ryt
		while(rytQ.top().dupIdx <= (i - k)) {
			rytQ.pop();
		}
		lftMax = lftQ.top().l;
		rytMin = rytQ.top().r;
		assert(lftMax == tmp.l);
		// cout << i << ":" << lftMax << " " << rytMin << endl;
 		int curAns = max(0,rytMin - lftMax + 1);
		if(curAns > ans) {
			ans = curAns;
			starting = i - k + 1;
			ending = i;
		}
	}
	cout << ans << endl;
	for (int i = starting; i <= ending; ++i) {
		cout << passes[i - 1].SS << " ";
	}
	cout << endl;
    return 0;
}