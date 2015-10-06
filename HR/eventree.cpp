#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


bool visited[101],graph[101][101];
vector<list<int> > adjlist(101);
int n,m;
int one,two,childcount[101];
int final;

void dfs(int node) {
	for (list<int>::iterator it = adjlist[node].begin(); it != adjlist[node].end() ; ++it) {
		adjlist[*it].remove(node);
		dfs(*it);
	}
}

int numberofchild(int node) {
	childcount[node] = 1;
	for (list<int>::iterator it = adjlist[node].begin(); it != adjlist[node].end() ; ++it) {
		childcount[node] += numberofchild(*it);
	}
	return childcount[node];
}

void recurse(int node) {
	for (list<int>::iterator it = adjlist[node].begin(); it != adjlist[node].end() ; ++it) {
		if(childcount[*it] % 2 == 0) final++;
		recurse(*it);
	}
}


int main()
{
	final = 0;
    slli2(n,m);
    for (int i = 0; i < m; ++i) {
    	si2(one,two);
    	adjlist[one].pb(two);
    	adjlist[two].pb(one);
    }
    dfs(1);
    numberofchild(1);
    recurse(1);
    pi(final);
    return 0;
}