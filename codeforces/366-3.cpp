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


deque<int> app[300005];
deque<PII> Q; //val,pos
bool read[300005];
int n,q,type;
int curans;
int removed;
int val;

int main()
{
	fill(read,false);
	removed = 0;
	curans = 0;
	si2(n,q);
	for (int i = 1; i <= q; ++i) {
		si2(type,val);		
		if(type == 1) {
			app[val].pb(i);
			read[i] = false;
			Q.pb(mp(val,i));
			curans++;
		}
		else if(type == 2) {
			while(!(app[val].empty())) {
				if(!read[app[val].front()]) {
					read[app[val].front()] = true;
					curans--;
				}
				app[val].pop_front();
			}
		}
		else {
			while(removed < val) {
				if(!read[Q.front().SS]) {
					read[Q.front().SS] = true;
					curans--;
				}
				removed++;
				Q.pop_front();
			}
		}
		pi(curans);
	}
    return 0;
}