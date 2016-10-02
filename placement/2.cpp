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
#define INF                     INT_MAX
#define N                       100007


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


int V,E,in,out,weight,one,two;
ll ans;
vector<pair<int,PII> > edges;
PII parent[N];


struct sort_pred {
    bool operator()(const std::pair<int,pair<int,int> > &left, const std::pair<int,pair<int,int> > &right) {
        return left.first < right.first;
    }
};


void makeset(int total) {
    for (int i = 1; i <= total; ++i) {
        parent[i].FF = i;
        parent[i].SS = 0;
    }
}

int findset(int number) {
    if(number == parent[number].FF) {
        return parent[number].FF;
    }
    else {
        parent[number].FF = findset(parent[number].FF);
        return parent[number].FF;
    }
}

void combine(int one,int two) {
    if(parent[one].SS > parent[two].SS) {
        parent[two].FF = parent[one].FF;
    }
    else if(parent[one].SS < parent[two].SS) {
        parent[one].FF = parent[two].FF;
    }
    else {
        parent[two].FF = parent[one].FF;
        parent[one].SS++;
    }
    return;
}



inline void Refresh() {
    
}

// main code begins now

int main()
{
	int tmp;
    scanf("%d %d",&V,&E);
    for (int i = 0; i < E; ++i) {
    	scanf("%d %d %d",&out,&in,&tmp);
    	if(tmp == 0) {
    		weight = 0;	
    	}
    	else {
    		scanf("%d",&weight);
    	}
    	edges.pb(mp(weight,mp(out,in)));
    }
    sort(edges.begin(),edges.end(),sort_pred());
    makeset(V+2);
    for (int i = 0; i < E; ++i) {
        one = findset(edges[i].SS.FF);
        two = findset(edges[i].SS.SS);
        if(one != two) {
            ans += (ll)edges[i].FF;
            combine(one,two);
        }
    }
    printf("%lld\n",ans);
    return 0;
}