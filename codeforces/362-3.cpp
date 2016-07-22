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


map<PLL,ll > modifiedRoads;



int main()
{
    ll q,Type,v,u,w;
    slli(q);
    for (int i = 0; i < q; ++i) {
    	slli(Type);
    	if(Type == 1) {
    		slli3(v,u,w);
    		vector<ll> pathU;
    		vector<ll> pathV;
    		while(v >= 1) {
    			pathV.pb(v);
    			v = v/2;
    		}
    		while(u >= 1) {
    			pathU.pb(u);
    			u = u/2;
    		}
    		int U,V;
    		U = pathU.size() - 1;
    		V = pathV.size() - 1;
    		for (; U >= 1 && V >= 1; --U,--V) {
    			if(pathU[U-1] != pathV[V-1]) {
    				break;
    			}
    		}
    		for (int i = 0; i < U; ++i) {
    			modifiedRoads[mp(min(pathU[i],pathU[i+1]),max(pathU[i],pathU[i+1]))] += w;
    		}
    		for (int i = 0; i < V; ++i) {
    			modifiedRoads[mp(min(pathV[i],pathV[i+1]),max(pathV[i],pathV[i+1]))] += w;
    		}
    	}
    	else {
    		ll ans = 0;
    		slli2(v,u);
    		vector<ll> pathU;
    		vector<ll> pathV;
    		while(v >= 1) {
    			pathV.pb(v);
    			v = v/2;
    		}
    		while(u >= 1) {
    			pathU.pb(u);
    			u = u/2;
    		}
    		int U,V;
    		U = pathU.size() - 1;
    		V = pathV.size() - 1;
    		for (; U >= 1 && V >= 1; --U,--V) {
    			if(pathU[U-1] != pathV[V-1]) {
    				break;
    			}
    		}
    		for (int i = 0; i < U; ++i) {
    			if(modifiedRoads.find( mp(min(pathU[i],pathU[i+1]),max(pathU[i],pathU[i+1])) ) != modifiedRoads.end()) {
    				ans += modifiedRoads[mp(min(pathU[i],pathU[i+1]),max(pathU[i],pathU[i+1]))];
    			}
    		}
    		for (int i = 0; i < V; ++i) {
    			if(modifiedRoads.find( mp(min(pathV[i],pathV[i+1]),max(pathV[i],pathV[i+1])) ) != modifiedRoads.end()) {
    				ans += modifiedRoads[mp(min(pathV[i],pathV[i+1]),max(pathV[i],pathV[i+1]))];
    			}
    		}
    		plli(ans);
    	}
    }
    return 0;
}
