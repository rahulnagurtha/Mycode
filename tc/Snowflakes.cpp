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

class Snowflakes {
public:
	vector <string> flareOut(vector <string> a){
		char one[51][51];
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 0; j < a[i].size(); ++j) {
				one[i][j] = a[i][j];
				one[j][i] = a[i][j];
			}
		}
		vector<string> two;
		string temp;
		for (int i = 0; i < a.size(); ++i) {
			temp = "";
			for (int j = 0; j < a.size(); ++j) {
				temp += one[i][a.size()-1-j];
			}
			two.pb(temp);
		}
		for (int i = 0; i < two.size(); ++i) {
			for (int j = 0; j < a.size(); ++j) {
				two[i] += one[i][j];
			}
		}
		vector<string> ans;
		for (int i = 0; i < two.size(); ++i) {
			ans.pb(two[two.size()-1-i]);
		}
		for (int i = 0; i < two.size(); ++i) {
			ans.pb(two[i]);
		}
		return ans;
	}
};


int main()
{

	Snowflakes test;
	test.
}

// <%:testing-code%>
// //Powered by [KawigiEdit] 2.0!
