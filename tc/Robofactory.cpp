#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define N                     	100007

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

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


class Robofactory
{
public:
	int reveal(vector <int> query, vector <string> answer) {
		vector<int> ans;
		vector<int> suspect;

		//can zero 
		for (int i = 1; i < query.size(); ++i) {
			//can this be corrupt
			bool isOdd;
			if((query[i] % 2) == 1) isOdd = true;
			else isOdd = false;
			if(isOdd) {	//its odd
				if(answer[i] == "Odd" ) {	//gave correct answer
					if((query[i-1] % 2) == 0) suspect.pb(i);
				}
				else {	//gave wrong answer
					
				}
			}
			else {

			}
		}


		if(ans.size() == 0) return 0;
		else if(ans.size() > 1) return -1;
		else return ans[0];
	}
	
};