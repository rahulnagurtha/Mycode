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

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

class DVDPlayer
{
public:
	vector<string> findMovies(vector<string> moviesWatched) {
		int curIdx;
		vector<string> final;
		string cur = moviesWatched[0];
		vector<pair<string,string> > ans;
		vector<pair<string,string> > mapping;
		for (int i = 0; i < moviesWatched.size(); ++i) {
			mapping.pb(mp(moviesWatched[i],moviesWatched[i]));
		}
		curIdx = 0;
		mapping[0].SS = "-1";
		for (int i = 1; i < moviesWatched.size(); ++i) {
			for (int j = 0; j < mapping.size(); ++j) {
				if(mapping[j].FF == cur) continue;
				if(mapping[j].FF == moviesWatched[i]) {
					mapping[curIdx].SS = mapping[j].SS;
					mapping[j].SS = "-1";
					cur = mapping[j].FF;
					curIdx = j;
					break;
				} 
			}
		}
		for (int i = 0; i < mapping.size(); ++i) {
			if ((mapping[i].SS != "-1") && (mapping[i].FF != mapping[i].SS)) {
				ans.pb(mp(mapping[i].FF,mapping[i].SS));
			}
		}
		sort(ans.begin(),ans.end());
		for (int i = 0; i < ans.size(); ++i) {
			final.pb(ans[i].FF + " is inside " + ans[i].SS + "'s case");
		}
		return final;
	}
};