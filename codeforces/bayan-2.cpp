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

VOVI graph(500),rgraph(500);
deque<int> layers;
bool status[500],rstatus[500];
int n,m,prenode;
string rows,columns;

// main code begins now

int main()
{
	fill(status,false);
	fill(rstatus,false);
    cin >> n >> m;
    cin >> rows;
    cin >> columns;
    for (int i = 0; i < rows.size(); ++i) {
    	if(rows[i] == '>') {
    		for (int j = m*i+1; j < m*(i+1); ++j) {
    			graph[j].push_back(j+1);
    		}
    		for (int j = m*(i+1); j > m*i+1; --j) {
    			rgraph[j].push_back(j-1);
    		}
    	}
    	else{
    		for (int j = m*i+1; j < m*(i+1); ++j) {
    			rgraph[j].push_back(j+1);
    		}
    		for (int j = m*(i+1); j > m*i+1; --j) {
    			graph[j].push_back(j-1);
    		}
    	}
    }
    for (int i = 0; i < columns.size(); ++i) {
    	if(columns[i] == '^') {
    		for (int j = i+1; j < i+(n-1)*m; j += m) {
    			graph[j+m].push_back(j);
    		}
    		for (int j = i+1; j < i+(n-1)*m; j += m) {
    			rgraph[j].push_back(j+m);
    		}
    	}
    	else{
    		for (int j = i+1; j < i+(n-1)*m; j += m) {
    			rgraph[j+m].push_back(j);
    		}
    		for (int j = i+1; j < i+(n-1)*m; j += m) {
    			graph[j].push_back(j+m);
			}
    	}
    }
    //bfs on graph
    layers.pb(1);
    status[1] = true;
    while(!layers.empty()) {
    	prenode = layers.front();
    	for (int i = 0; i < graph[prenode].size(); ++i) {
    		if(status[graph[prenode][i]] == false) {
    			status[graph[prenode][i]] = true;
    			layers.pb(graph[prenode][i]);
    		}
    	}
    	layers.pop_front();
    }
    //bfs on reverse graph
    layers.pb(1);
    rstatus[1] = true;
    while(!layers.empty()) {
    	prenode = layers.front();
    	for (int i = 0; i < rgraph[prenode].size(); ++i) {
    		if(rstatus[rgraph[prenode][i]] == false) {
    			rstatus[rgraph[prenode][i]] = true;
    			layers.pb(rgraph[prenode][i]);
    		}
    	}
    	layers.pop_front();
    }
    for (int i = 1; i <= n*m; ++i) {
    	if(status[i] == false || rstatus[i] == false) {
    		printf("NO\n");
    		return 0;
    	}
    }
    printf("YES\n");
    return 0;
}