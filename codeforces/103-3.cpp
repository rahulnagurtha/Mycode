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


int aFreq[26];
int pFreq[26];
int qCnt;
int ans;
string a,p;




inline void initialise() {
    fill(pFreq,0);
	fill(aFreq,0);
}

void validateAndDecide() {
	bool isGood = true;
	int aCnt = 0;
	int pCnt = 0;
	for (int i = 0; i < 26; ++i) {
		isGood = (isGood && (aFreq[i] <= pFreq[i]));
		aCnt += aFreq[i];
		pCnt += pFreq[i];
	}
	// cout << aCnt << " " << qCnt << " " << pCnt << endl;
	isGood = (isGood && ((aCnt + qCnt) == pCnt));
	if(isGood) ans++;
	return;
}


int main()
{
	initialise();
	cin >> a;
	cin >> p;
	for (int i = 0; i < p.size(); ++i) {
		pFreq[p[i] - 'a']++;
	}
	for (int i = 0; i < min(p.size() - 1,a.size()); ++i) {
		if(a[i] != '?') aFreq[a[i] - 'a']++;
		else qCnt++;
	}
	for (int i = p.size() - 1; i < a.size(); ++i) {
		// cout << a[i] << " ";
		if(a[i] == '?') qCnt++;
		else aFreq[a[i] - 'a']++;
		validateAndDecide();
		if(a[i - p.size() + 1] == '?') qCnt--;
		else aFreq[a[i - p.size() + 1] - 'a']--;
	}
	cout << ans << endl;
    return 0;
}