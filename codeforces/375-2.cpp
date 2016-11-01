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






inline void Refresh() {
    
}


int main()
{
	ll n;
	ll maxInside = 0;
	ll maxOutside = 0;
	VS outside;
	VS inside;
	VS newInside;
	string A;
	string brandNew;
	cin >> n;
	cin >> A;
	for (int i = 0; i < A.size(); i++) {
		if(A[i] != '(') {
			brandNew += A[i];
			continue;
		}
		brandNew += '(';
		i++;
		string tmp;
		while(i < A.size() && A[i] != ')') {
			tmp += A[i];
			i++;
		}
		if(i < A.size() && A[i] == ')') brandNew += ')';
		inside.pb(tmp);
	}
	for (int i = 0; i < brandNew.size(); ++i) {
		if(brandNew[i] == '_' || brandNew[i] == '(') continue;
		string tmp;
		while(i < brandNew.size() && !(brandNew[i] == '(' || brandNew[i] == ')' || brandNew[i] == '_')) {
			tmp += brandNew[i];
			i++;
		}
		outside.pb(tmp);
	}
	for (int i = 0; i < inside.size(); ++i) {
		for (int j = 0; j < inside[i].size(); ++j) {
			if(inside[i][j] == '_') continue;
			string tmp;
			while(j < inside[i].size() && inside[i][j] != '_') {
				tmp += inside[i][j];
				j++;
			}
			newInside.pb(tmp);

		}
	}
	for (int i = 0; i < outside.size(); ++i) {
		maxOutside = max(maxOutside,(ll)outside[i].size());
	}
	for (int i = 0; i < newInside.size(); ++i) {
		if(newInside[i].size() > 0) maxInside++;
	}
	cout << maxOutside << " " << maxInside << endl;
    return 0;
}