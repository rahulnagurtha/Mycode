#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			    ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			    (a-(box(a,b))*b)
#define ceil(a,b) 			    ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			    ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


vector<vector<PII> > graph(100005);
int adj[100005],n,u,v,rep,temp;
deque<int> layer;
vector<int> answer;

void solve() {
	int flag = 0;
	for (int i = 2; i <= n; ++i) {
		if(adj[i] == 1) {
			layer.pb(i);
		}
	}
	while(!layer.empty()) {
		temp = layer.front();
		
		//process this node
		if(graph[temp][0].SS == 1) {
			adj[temp]--;
			adj[graph[temp][0].FF]--;
			if(adj[graph[temp][0].FF] == 1 && graph[temp][0].FF != 1) layer.pb(graph[temp][0].FF);
		}
		else {
			answer.pb(temp);
		}
		layer.pop_front();
	}
	printf("%d\n",answer.size());
	for (int i = 0; i < answer.size(); ++i) {
		printf("%d ",answer[i]);
	}
}


// main code begins now

int main()
{
    scanf("%d",&n);
    for (int i = 1; i < n; ++i) {
    	scanf("%d %d %d",&u,&v,&rep);
    	adj[u]++;
    	adj[v]++;
    	graph[u].pb(mp(v,rep));
    	graph[v].pb(mp(u,rep));
    }
    solve();
    return 0;
}