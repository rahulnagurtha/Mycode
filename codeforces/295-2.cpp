#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int foo,k;
int parent[20005];
int V,E,in,out,curlayer,answer,N,M;
vector<vector<int> > graph(20005);
deque<pair<int,int> > layers;
bool status[20005];


// main code begins now

int main()
{
    //declaration and input	
    cin >> N >> M;
    if(N >= M) {
        printf("%d\n",N-M);
        return 0;
    }
    for (int j = 1; j <= 20005 ; ++j) {
    	status[j]=false;
    }
    graph[1].push_back(2);
	for (int i = 2; i < M; ++i) {
       graph[i].push_back(i-1);
       graph[i].push_back(2*i); 
    }
    for (int i = M+1; i <= 2*M; ++i) {
        graph[i].push_back(i-1);
    }
    layers.push_back(make_pair(N,0));
    //end of declaration and input

    
    //start of bfs
    while(!layers.empty()) {
    	foo = layers.front().first;
        // curlayer = layers.front().second;
        for (int it = 0; it < graph[foo].size(); ++it) {
            if (status[graph[foo][it]] == false) {
                if(graph[foo][it] == M) {
                    layers.clear();
                    answer = layers.front().second+1;
                    layers.push_back(make_pair(graph[foo][it],layers.front().second+1));
                    break;
                }
                status[graph[foo][it]] = true;
                layers.push_back(make_pair(graph[foo][it],layers.front().second+1));
            }
        }
        layers.pop_front();
    }
    //end of bfs

    printf("%d\n",answer);
    return 0;
}