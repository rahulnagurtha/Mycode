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

class ArrayHash {
public:
	int getHash(vector <string> a){
		int ans = 0;
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 0; j < a[i].size(); ++j) {
				ans += (int)(a[i][j]-'A');
			}
		}
		for (int i = 0; i < a.size(); ++i) {
			ans += i*a[i].size();
		}
		for (int i = 0; i < ; ++i) {
			ans += ( (a[i].size())*(a[i].size()-1) )/2;
		}
		return ans;
	}
};

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
