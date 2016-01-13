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

class AlienAndPassword {
public:
	int getNumber(string a){
		vector<string> ans;
		string temp;
		for (int i = 0; i < a.size(); ++i) {
			temp = "";
			for (int j = 0; j < i; ++j) {
				temp += a[j];
			}
			for (int j = i+1; j < a.size(); ++j) {
				temp += a[j];
			}
			bool add = true;
			for (int j = 0; j < ans.size(); ++j) {
				if(ans[j] == temp) {
					add = false;
					break;
				}
			}
			if(add) ans.pb(temp);
		}
	}
};

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
