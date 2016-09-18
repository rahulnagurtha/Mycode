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

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF 					INT_MAX
#define N                     	500007


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

int n,m,p;

struct node {
	int lft,ryt,partner;
	bool isAlive;
};

node A[N];

void assign(node &cur,int l,int r,int match,bool isAlive) {
	cur.lft = l;
	cur.ryt = r;
	cur.isAlive = true;
	cur.partner = match;
	return;
}

int main()
{

	stack<int> T;
    string seq,operations;
    cin >> n >> m >> p;
    cin >> seq;
    cin >> operations;
    for (int i = 0; i < seq.size(); ++i) {
    	if(seq[i] == '(') T.push(i+1);
    	else {
    		assign(A[T.top()],max(1,T.top()-1),min(T.top()+1,n),i+1,true);
    		assign(A[i+1],max(1,i),min(i+2,n),T.top(),true);
    		T.pop();
    	}
    }
    // for (int i = 1; i <= n; ++i) {
    // 	cout << i << "<>" << A[i].lft << " " << A[i].ryt << " " << A[i].partner << endl; 
    // }
    for (int i = 0; i < operations.size(); ++i) {
    	if(operations[i] == 'L') p = A[p].lft;
    	else if(operations[i] == 'R') p = A[p].ryt;
    	else {
    		int lft = min(p,A[p].partner);
    		int ryt = max(p,A[p].partner);
    		int nxtRyt = A[ryt].ryt;
    		int prevLft = A[lft].lft;
    		if(ryt != nxtRyt) p = nxtRyt;
    		else p = prevLft;
    		if(nxtRyt != ryt && prevLft != lft) {
    			A[prevLft].ryt = nxtRyt;
    			A[nxtRyt].lft = prevLft;
    		}
    		else if(nxtRyt == ryt) {
    			A[prevLft].ryt = prevLft;
    		}
    		else {
    			A[nxtRyt].lft = nxtRyt;
    		}
    		int cur = lft;
    		while(cur <= ryt) {
    			A[cur].isAlive = false;
    			cur = max(cur + 1,A[cur].ryt);
    		}
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	if(A[i].isAlive) cout << seq[i-1];
    }
    printf("\n");
    return 0;
}