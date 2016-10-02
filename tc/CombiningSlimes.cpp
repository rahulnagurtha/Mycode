#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

class CombiningSlimes {
public:
	int maxMascots(vector<int> a){
		priority_queue<int, std::vector<int>, std::greater<int> Q(a.begin(),a.end());
		int ans = 0,one,two;
		while(Q.size() > 1) {
			one = Q.top();
			Q.pop();
			two = Q.top();
			Q.pop();
			ans += one*two;
			Q.push(one + two);
		}
		return ans;
	}
};

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
