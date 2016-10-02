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
	SYNC;
	vector<pair<string,int> > answer;
    priority_queue<int,vector<int>,greater<int> > Q;
    string type;
    int n,number;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> type;
    	if(type == "insert") {
    		cin >> number;
    		Q.push(number);
    		answer.pb(mp(type,number));
    	}
    	else if(type == "getMin") {
    		cin >> number;
    		if(Q.empty()) {
    			answer.pb(mp("insert",number));
    			Q.push(number);
    		}
    		else {
    			if(Q.top() != number) {
    				while(!Q.empty() && Q.top() < number) {
    					answer.pb(mp("removeMin",-1));
    					Q.pop();
					}
    				if(Q.empty() || Q.top() > number) {
    					answer.pb(mp("insert",number));
    					Q.push(number);
    				}
    			} 
    		}
	    	answer.pb(mp("getMin",number));
    	}
    	else {
    		if(Q.empty()) {
    			answer.pb(mp("insert",1));
    			Q.push(1);
    		}
    		Q.pop();
    		answer.pb(mp("removeMin",-1));
    	}
    	// cout << Q.size() << endl;
    }
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); ++i) {
    	if(answer[i].FF == "removeMin") cout << "removeMin" << endl;
    	else {
    		cout << answer[i].FF << " " << answer[i].SS << endl;
    	}
    }
    return 0;
}