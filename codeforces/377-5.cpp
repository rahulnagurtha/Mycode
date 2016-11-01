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





int n,m;
int p[N];
VOII s;
int socketP[N];
map<int,vector<PII> > computer;
map<int,vector<PII> > newComputer;
int numOfAdapter[N];
int connectedTo[N];

int main()
{
	int maximum = 0;
	int minimum = 0;
	int tmp;
	si2(n,m);
	for (int i = 1; i <= n; ++i) {
		si(p[i]);
		computer[p[i]].pb(mp(-1,i));
	}
	for (int i = 1; i <= m; ++i) {
		si(tmp);
		socketP[i] = tmp;
		s.pb(mp(tmp,i));
	}
	sort(s.begin(),s.end());
	for (int i = m - 1; i >= 0; --i) {
		tmp = s[i].FF;
		while(tmp > 0) {
			auto it = computer.find(tmp);
			if(it != computer.end() && (it->SS).size() != 0 && (it->SS).back().FF == -1) {
				(it->SS).back().FF = s[i].SS;
				newComputer[it->FF].pb((it->SS).back());
				(it->SS).pop_back();
				break;
			}
			int oldTemp = tmp;
			tmp = ceil(tmp,2);
			if(tmp == oldTemp) break;
		}
	}
	for (auto it = newComputer.begin(); it != newComputer.end() ; ++it) {
		VOII B = it->SS;
		for (int i = 0; i < B.size(); ++i) {
			
			if(B[i].FF != -1) {
				connectedTo[B[i].SS] = B[i].FF;
				maximum++;
				tmp = socketP[B[i].FF];
				while(tmp != p[B[i].SS]) {
					numOfAdapter[B[i].FF]++;
					minimum++;
					int oldTemp = tmp;
					tmp = ceil(tmp,2);
					if(tmp == oldTemp) break;
				}
			}
		}
	}
	printf("%d %d\n",maximum,minimum);
	for (int i = 1; i <= m; ++i) {
		printf("%d ",numOfAdapter[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ",connectedTo[i]);
	}
	printf("\n");
    return 0;
}