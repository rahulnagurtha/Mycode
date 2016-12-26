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






inline void Refresh() {
    
}


void update(PII &src,char dir) {
	if(dir == 'L') src.FF--;
	else if(dir == 'R') src.FF++;
	else if(dir == 'U') src.SS++;
	else src.SS--;
	return;
}

bool isOptimal(PII p_1,PII p_2,int dis) {
	return ((abs(p_1.FF - p_2.FF) + abs(p_1.SS - p_2.SS)) == dis);
}

int main()
{
	int n;
	int ans = 0;
	string a;
	PII last_point = mp(0,0);
	PII cur_point = mp(0,0);
	int dis = 0;
	cin >> n;
	cin >> a;
	for (int i = 0; i < a.size(); ++i) {
		PII tmp = cur_point;
		update(cur_point,a[i]);
		dis++;
		if(!isOptimal(last_point,cur_point,dis)) {
			// cout << cur_point << " " << last_point << " " << dis << endl;
			last_point = tmp;
			ans++;
			dis = 1;
		}
	}
	ans++;
	cout << ans << endl;
    return 0;
}