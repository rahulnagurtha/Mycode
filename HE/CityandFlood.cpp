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
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define N 						100005

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


int n,k;
struct info {
	int rank;
	int parent;
}kingdom[N];

bool visited[N];

void initialise() {
	for (int i = 0; i < N; ++i) {
		kingdom[i].parent = i;
		kingdom[i].rank = 0;
	}
	fill(visited,false);
	return;
}

void merge(int idxOne,int idxTwo) {
	if(idxOne == idxTwo) return;
	if(kingdom[idxOne].rank > kingdom[idxTwo].rank) {
		kingdom[idxTwo].parent = idxOne;
	}
	else {
		kingdom[idxOne].parent = idxTwo;
		if(kingdom[idxTwo].rank == kingdom[idxOne].rank) {
			kingdom[idxTwo].rank++;
		}
	}
	return;
}

int capital(int cur) {
	if(cur != kingdom[cur].parent) {
		kingdom[cur].parent = capital(kingdom[cur].parent);
	}
	return kingdom[cur].parent;	
}

int main()
{
	initialise();
    si2(n,k);
    int a,b;
    int tmp;
    int autonomusKingdoms = 0;
    for (int i = 0; i < k; ++i) {
    	si2(a,b);
    	merge(capital(a),capital(b));
    }
    for (int i = 1; i <= n; ++i) {
    	tmp = capital(i);
    	if(!visited[tmp]) {
    		visited[tmp] = true;
    		autonomusKingdoms++;
    	}
    }
    pi(autonomusKingdoms);
    return 0;
}