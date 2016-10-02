#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{
    //declaration and input
	int foo,k;
    int parent[100];
    int V,E,in,out;
    vector<vector<int> > graph(100);
    deque<int> layers;
    bool status[100];
    printf("enter number of vertices and edges in same order: \n");
    cin >> V >> E;
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
    layers.push_back(foo);
    parent[foo] = 0 ;
    //end of declaration and input

    
    //start of bfs
    while(!layers.empty()) {
    	foo = layers.front();
        for (int it = 0; it < graph[foo].size(); ++it) {
            if (status[graph[foo][it]] == false) {
                parent[graph[foo][it]] = foo;
                status[graph[foo][it]] = true;
                layers.push_back(graph[foo][it]);
            }
        }
        layers.pop_front();
    }
    //end of bfs

    printf("reachable nodes are:\n");
    for (int i = 1; i <= V ; ++i) {
    	if (status[i]==true) {
    		printf("%d->",i);
    	}
    }
    printf("\n\nParents of nodes in bfs tree are:\n");
    for (int i = 1; i <= V ; ++i) {
        printf("%d->%d\n",i,parent[i]);
    }
    return 0;
}