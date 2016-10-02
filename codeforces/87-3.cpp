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

VOVI graph(2005);
bool status[2005];
deque<int> layer;
VI root;
int depth[2005],parent[2005],temp,n;
// main code begins now

int main()
{
	cin >> n ;
	for (int i = 1; i <= n; ++i) {
		cin >> temp;
		if(temp != -1) graph[temp].pb(i);
		else root.pb(i);
	}
	for (int i = 0; i < root.size(); ++i) {
		layer.pb(root[i]);		
		while(!layer.empty()) {
			temp = layer.front();
			layer.pop_front();
			if(status[temp] == true) continue;
			status[temp] = true;
			for (int i = 0; i < graph[temp].size(); ++i) {
				if(status[graph[temp][i]] == false) {
					parent[graph[temp][i]] = temp;
					depth[graph[temp][i]] = depth[temp] + 1;
					layer.push_front(graph[temp][i]);
				}
			}
		}
	}
	temp = -1;
	for (int i = 1; i <= n; ++i) {
		if(depth[i] > temp) temp = depth[i];
		// printf("%d ",depth[i]);
	}
	// printf("\n");
	printf("%d\n",temp+1);
    return 0;
}