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

#define rep(i,a,b)				for(int i = (a); (i) <= (b); (i)++)
#define per(i,a,b)				for(int i = (a); (i) >= (b); (i)--)
#define reps(i,a,b,s)			for(int i = (a); (i) <= (b); i += (s))
#define pers(i,a,b,s)			for(int i = (a); (i) >= (b); i -= (s))

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



string a;
int lps[10*N];
set<int> info;

void preProcess() {
	lps[0] = 0;
	for (int i = 1; i < a.size(); ++i) {
		int last = lps[i-1];
		while(a[last] != a[i] && last != 0) {
			last = lps[last-1];
		}
		if(last == 0) lps[i] = (a[last] != a[i] ? 0 : 1);
		else lps[i] = last + 1;
	}
	return;
}


int main()
{
	SYNC;
	cin >> a;
	preProcess();
	for (int i = 1; i < a.size() - 1; ++i) {
		if(lps[i] > 0) info.insert(lps[i]);
	}
	int idx = a.size() - 1;
	while(idx > 0) {
		int len = lps[idx];
		if(info.find(len) != info.end()) {
			for (int i = 0; i < len; ++i) {
				cout << a[i];
			}
			cout << endl;
			return 0;
		}
		else {
			idx = lps[idx] - 1;
		}
	}
	cout << "Just a legend" << endl;
    return 0;
}