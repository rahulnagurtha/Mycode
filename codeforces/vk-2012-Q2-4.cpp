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
#define N                     	2007


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



ll ans;
ll fromHere[N];
bool isPalindrome[N][N];



int main()
{
	string a;
	cin >> a;
	fill(isPalindrome,false);
	for (int len = 1; len <= a.size(); ++len) {
		for (int lft = 0; lft + len - 1 < a.size(); ++lft) {
			int ryt = lft + len - 1;
			if(a[lft] == a[ryt]) {
				isPalindrome[lft][ryt] = true;
				if(lft + 1 <= ryt - 1) {
					isPalindrome[lft][ryt] &= isPalindrome[lft + 1][ryt - 1]; 
				}
			}
		}
	}
	fromHere[a.size()] = 0;
	for (int i = a.size() - 1; i >= 0; --i) {
		fromHere[i] += fromHere[i+1];
		for (int j = i; j < a.size(); ++j) {
			if(isPalindrome[i][j]) fromHere[i]++; 
		}
	}
	for (int i = 0; i < a.size(); ++i) {
		for (int j = i; j < a.size(); ++j) {
			if(isPalindrome[i][j]) ans += fromHere[j+1];
		}
	}
	cout << ans << endl;
    return 0;
}