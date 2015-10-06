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
typedef vector<VL> VOVL;


bool graph[105][105];
deque<LL> layer;
bool status[105];
LL n,x,y,temp,type;
VOLL intervals;


void printgraph() {
	printf("new graph:\n");
	for (int i = 1; i <= intervals.size(); ++i) {
		for (int j = 1; j <= intervals.size(); ++j) {
			cout << graph[i][j] << " ";
		}
		printf("\n");
	}
}


void addint(LL a,LL b) {
	fill(status,false);
	for (int i = 0; i < intervals.size(); ++i) {
		//reach directly from new to i+1
		if( ( intervals[i].FF < a && a < intervals[i].SS ) || ( intervals[i].FF < b && b < intervals[i].SS ) ) {
			graph[intervals.size()+1][i+1] = true;
		}
		else {
			for (int j = 1; j <= 100; ++j) {
				if(graph[intervals.size()+1][j] == true && graph[j][i+1] == true) {
					graph[intervals.size()+1][i+1] = true;
					break;
				}
			}
		}
		//reach from i+1 to new
		if( ( a < intervals[i].FF && intervals[i].FF < b ) || ( a < intervals[i].SS && intervals[i].SS < b ) ) {
			graph[i+1][intervals.size()+1] = true;
		}
		else {
			for (int j = 1; j <= 100; ++j) {
				if(graph[i+1][j] == true && graph[j][intervals.size()+1] == true) {
					graph[i+1][intervals.size()+1] = true;
					break;
				}
			}
		}
	}
	intervals.pb(mp(a,b));
	// printgraph();
	return;
}


void bfs(LL a,LL b) {
	fill(status,false);
	layer.pb(a);
	status[a] = true;
	while(!layer.empty()) {
		temp = layer.front();
		for (int i = 1; i <= 100; ++i) {
			if(graph[temp][i] == true && status[i] == false) {
				status[i] = true;
				layer.pb(i);
			}
		}
		layer.pop_front();
	}
	if(status[b] == true) printf("YES\n");
	else printf("NO\n");
	return;
}


int main()
{
	fill(graph,false);
    // freopen("in.txt", "r", stdin);
    cin >> n ;
    for (int i = 0; i < n; ++i) {
    	cin >> type >> x >> y ;
    	if(type == 1) {
    		addint(x,y);
    	}
    	else {
    		bfs(x,y);
    	}
    }
    return 0;
}