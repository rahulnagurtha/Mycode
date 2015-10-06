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

// main code begins now

int main()
{
    //declaration and input
    vector<int> noincoming;
    vector<int> t_order;
    vector<VI> graph(100);
    int V,E,in,out,temp;
    int incomingcount[100];
    printf("enter number of vertices and edges in same order: \n");
    cin >> V >> E ;
    for (int i = 1; i <= V; ++i) {
    	incomingcount[i] = 0 ;
    }
    printf("enter the edges seperated by a line,each line is of the form 'u v' if the edge is u->v\n");
    for (int i = 0; i < E; ++i) {
    	cin >> out >> in ;
    	graph[out].push_back(in);
    }
    //end of declaration and input

    //sorting starts
    
    //setting up the incoming edges count for each vertex
    for (int i = 1; i <= V; ++i) {
    	for (int j = 0; j < graph[i].size(); ++j) {
    		incomingcount[graph[i][j]]++;
    	}
    }

    //adding vertices to the set
    for (int i = 1; i <= V; ++i) {
    	if(incomingcount[i] == 0) noincoming.push_back(i);
    }

    //remove the edges after selcting any vertex from the set
    while(!noincoming.empty()) {
    	temp = noincoming[noincoming.size()-1];
    	noincoming.pop_back();
    	t_order.push_back(temp);
    	for (int i = 0; i < graph[temp].size(); ++i) {
    		incomingcount[graph[temp][i]]--;
    		if (incomingcount[graph[temp][i]] == 0) {
    			noincoming.push_back(graph[temp][i]);
    		}
    	}
    }

    for (int i = 0; i < t_order.size(); ++i) {
    	cout << t_order[i] << "->";
    }
    printf("\n");
    return 0;
}