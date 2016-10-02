#include <bits/stdc++.h>

using namespace std;

int foo,k,V,E,in,out;
vector<vector<int> > graph(100);
bool status[100];


void dfs(int foo) {
	for (int it = 0; it < graph[foo].size() ; ++it) {
		if (status[graph[foo][it]] == false) {
   			status[graph[foo][it]]=true;
    		dfs(graph[foo][it]);
    	}
	}
}


// main code begins now

int main()
{
    printf("enter number of vertices and edges in same order: \n");
    cin >> V >> E ;
    printf("enter the edges seperated by a line,each line is of the form 'u v' if the edge is u->v\n");
    for (int j = 1; j <= V ; ++j) {
    	status[j]=false;
    }
	for (int i = 0; i < E; ++i) {
        cin >> out >> in ;
        graph[out].push_back(in);
    }
    printf("\n");
    printf("starting node: \n");
    cin >> foo ;
    
    //dfs
    dfs(foo);
    printf("reachable nodes are:\n");
    for (int i = 1; i <= V ; ++i) {
    	if (status[i]==true) {
    		printf("%d->",i);
    	}
    }

    return 0;
}