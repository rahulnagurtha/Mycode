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

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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



ll n,m;
map<ll,ll> cnt;
set<ll> dis;
vector<VL> groups;
int compNumber[10*N];
int sizeOfComp[10*N];
ll fact[10*N];

void initialise() {
	fill(compNumber,-1);
	fill(sizeOfComp,0);
	fact[0] = 1;
	for (ll i = 1; i <= 10*N; ++i) {
		fact[i] = (fact[i-1]*i)%MOD;
	}
	return;
}


void solve() {
	ll nextComp = 1;
	for (ll i = 0; i < groups.size(); ++i) {
		//check if any one is assigned
		map<ll,VL> tmpGroups;
		VL unAssigned;
		for (int j = 0; j < groups[i].size(); ++j) {
			if(compNumber[groups[i][j]] != -1) {
				tmpGroups[compNumber[groups[i][j]]].pb(groups[i][j]);
			}
			else unAssigned.pb(groups[i][j]);
		}
		// cout << tmpGroups << endl;
		// cout << unAssigned << endl;
		for (int j = 0; j < unAssigned.size(); ++j) {
			compNumber[unAssigned[j]] = nextComp;
		}
		if(unAssigned.size() != 0) {
			sizeOfComp[nextComp] = unAssigned.size();
			nextComp++;
		}
		// go through each complicated group
		for (auto it = tmpGroups.begin(); it != tmpGroups.end(); ++it) {
			int groupNum = it->FF;
			VL curAssignedGroup = it->SS;
			if(sizeOfComp[groupNum] == curAssignedGroup.size()) continue;
			sizeOfComp[groupNum] -= curAssignedGroup.size();
			for (int j = 0; j < curAssignedGroup.size(); ++j) {
				compNumber[curAssignedGroup[j]] = nextComp;
			}
			sizeOfComp[nextComp] = curAssignedGroup.size();
			nextComp++;
		}
		// cout << "Total groups now : " << nextComp - 1 << endl;
		// for (int k = 1; k < nextComp; ++k) {
		// 	cout << sizeOfComp[k] << " ";
		// }
		// printf("\n");
	}
	ll ans = 1;
	for (int i = 1; i < nextComp; ++i) {
		ans = ans*fact[sizeOfComp[i]];
		ans %= MOD;
	}
	ans = (ans*(fact[(m - dis.size())])) % MOD;
	plli(ans);
}

int main()
{
	initialise();
	ll tmp,num;
	ll curType;
	slli2(n,m);
	// cin >> n >> m;
	for (ll i = 0; i < n; ++i) {
		slli(num);
		// cin >> num;
		map<ll,ll> cnt;
		map<ll,VL> data;
		for (ll j = 0; j < num; ++j) {
			slli(curType);
			// cin >> curType;
			dis.insert(curType);
			cnt[curType]++;	
		}
		for (auto it = cnt.begin();it != cnt.end(); ++it) {
			data[it->SS].pb(it->FF);
		}
		for (auto it = data.begin();it != data.end(); ++it) {
			groups.pb(it->SS);
		}
	}
	//grouping done
	solve();
    return 0;
}