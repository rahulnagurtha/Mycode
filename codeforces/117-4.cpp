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




VI one,two;
bool isSame[N];
string s_one,s_two;
int lps_one[N],lps_two[N];
bool is_div_one[N],is_div_two[N];

void preProcess() {
	lps_one[0] = 0;
	for (int i = 1; i < s_one.size(); ++i) {
		int last = lps_one[i-1];
		while(s_one[last] != s_one[i] && last != 0) {
			last = lps_one[last-1];
		}
		if(last == 0) lps_one[i] = (s_one[last] != s_one[i] ? 0 : 1);
		else lps_one[i] = last + 1;
	}
	lps_two[0] = 0;
	for (int i = 1; i < s_two.size(); ++i) {
		int last = lps_two[i-1];
		while(s_two[last] != s_two[i] && last != 0) {
			last = lps_two[last-1];
		}
		if(last == 0) lps_two[i] = (s_two[last] != s_two[i] ? 0 : 1);
		else lps_two[i] = last + 1;
	}
	return;
}


int main()
{
	int ans = 0;
	cin >> s_one;
	cin >> s_two;
	preProcess();
	int idx = s_one.size() - 1;
	while(idx > 0) {
		int len = lps_one[idx];
		if(s_one.size() % (s_one.size() - len) == 0) is_div_one[s_one.size() - len - 1] = true;
		idx = lps_one[idx] - 1;
	}
	idx = s_two.size() - 1;
	while(idx > 0) {
		int len = lps_two[idx];
		if(s_two.size() % (s_two.size() - len) == 0) is_div_two[s_two.size() - len - 1] = true;
		idx = lps_two[idx] - 1;
	}
	is_div_one[s_one.size() - 1] = true;
	is_div_two[s_two.size() - 1] = true;
	for (int i = 0; i < min(s_one.size(),s_two.size()); ++i) {
		if(s_one[i] != s_two[i]) break;
		if(is_div_one[i] && is_div_two[i]) ans++;
	}
	cout << ans << endl;
    return 0;
}