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
    int caseNumber = 1;
    while(t--) {
    	cout << "Case " << caseNumber << ": ";
    	caseNumber++;
    	string a;
    	cin >> a;
    	VS pieces;
    	VI sizes;
    	string tmp;
    	tmp += a[0];
    	pieces.pb(tmp);
    	priority_queue<int,VI,less<int> > Q;
    	for (int i = 1; i < a.size(); ++i) {
    		if(pieces.back().back() == a[i]) {
    			pieces[pieces.size() - 1] += a[i];
    		}
    		else {
    			string tmp;
		    	tmp += a[i];
		    	pieces.pb(tmp);
    		}
    	}
    	if(pieces.size() > 1) {
    		if(pieces[0][0] == pieces.back().back()) {
    			pieces[0] += pieces.back();
    			pieces.pop_back();
    		}
    	}
    	for (int i = 0; i < pieces.size(); ++i) {
    		Q.push(pieces[i].size());
    	}
    	if(pieces.size() == 1) {
    		cout << max(1,(int)pieces[0].size()/2) << endl;
    		return 0;
    	}
    	if(pieces.size() == 2) {
    		int lft = pieces[0].size();
    		int ryt = pieces[1].size();
    		if(lft == 1 && ryt == 1) {
    			cout << "2" << endl;
    		}
    		else if((lft == 1 && ryt == 2) || (lft == 2 && ryt == 1)) {
    			cout << "2" << endl;
    		}
    		else if(lft >= 3 && ryt == 2) {
    			cout << min(lft + 1,lft/2) << endl;
    		}
    		else if(lft == 2 && ryt >= 3) {
    			cout << min(ryt + 1,ryt/2) << endl;
    		}
    		else {
    			cout << min(max(lft,ryt/2),max(lft/2,ryt)) << endl;
    		}
    		return 0;
    	}
    	// cout << pieces << endl;
    	int finalAns = INT_MAX;
    	for (int i = 0; i < pieces.size(); ++i) {
    		//what if we replace here
    		int currentMax = Q.top();
    		int ansInThisCase;
    		if(pieces[i].size() == currentMax) {
    			Q.pop();
    			int sz = pieces.size();
    			int lft = pieces[rem(i-1,sz)].size();
    			int ryt = pieces[rem(i+1,sz)].size();
    			if(pieces[i].size() == 1) {
    				ansInThisCase = max(Q.top(),lft + 1 + ryt);
    			}
    			else if(pieces[i].size() == 2) {
    				ansInThisCase = max(Q.top(),min(lft + 1,ryt + 1));
    			}
    			else {
    				ansInThisCase = max(Q.top(),(int)pieces[i].size()/2);
    			}
    			Q.push(currentMax);
    		}
    		else {
    			int lft = pieces[rem(i - 1,(int)pieces.size())].size();
    			int ryt = pieces[rem(i + 1,(int)pieces.size())].size();
    			if(pieces[i].size() == 1) {
    				ansInThisCase = max(currentMax,lft + 1 + ryt);
    			}
    			else if(pieces[i].size() == 2) {
    				ansInThisCase = max(currentMax,min(lft + 1,ryt + 1));
    			}
    			else {
    				ansInThisCase = max(currentMax,Q.top());
    			}
    		}
    		finalAns = min(ansInThisCase,finalAns);
    	}
    	cout << finalAns << endl;
    }
    return 0;
}