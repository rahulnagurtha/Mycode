
#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			   ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			   (a-(box(a,b))*b)
#define ceil(a,b) 			  ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			  ((a%b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;




// main code begins now

int main()
{
    int foo,k,temp,V,E,in,out;
    vector<int> v;
    vector<vector<int> > graph;
    deque<int> storage;
    bool status[100];
    for (int j = 1; j <= 100 ; ++j) {
        status[j]=false;
        graph.push_back(v);
    }
    printf("enter number of vertices and edges in same order: \n");
    cin >> V >> E ;
    printf("enter the edges seperated by a line,each line is of the form 'u v' if the edge is u->v\n");
    for (int i = 0; i < E; ++i) {
        cin >> out >> in ;
        graph[out].push_back(in);
    }


	printf("\n");
    printf("starting node: \n");
    cin >> foo ;
    storage.push_back(foo);

    //dfs iteration
    while(!storage.empty()) {
    	temp = storage.front();
    	storage.pop_front();
    	if (status[temp] == false) {
    		status[temp] = true;
    		for (int it = 0; it < graph[temp].size(); ++it) {
				if (status[graph[temp][it]] == false) {
                    storage.push_front(graph[temp][it]);
                }
			}
    	}
    }
    //dfs complete

	printf("reachable nodes are:\n");
    for (int i = 1; i <= E ; ++i) {
    	if (status[i]==true) {
    		printf("%d->",i);
    	}
    }
    return 0;
}