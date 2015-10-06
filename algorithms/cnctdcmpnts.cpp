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
    vector<VI> components;
    vector<VI> graph(100);
	vector<VI> rgraph(100);
	set<int> vertices;
	deque<int> layers;
	VI temp;
	int V,E,in,out,foo;
	bool status[100],rstatus[100];
	set<int>::iterator it;
	printf("enter number of vertices and edges in same order: \n");
    cin >> V >> E ;
    for (int i = 1; i <= V ; ++i) {
    	vertices.insert(i);
    }
    printf("enter the edges seperated by a line,each line is of the form 'u v' if the edge is u->v\n");
    for (int i = 0; i < E; ++i) {
    	cin >> out >> in ;
    	graph[out].push_back(in);
    	rgraph[in].push_back(out);
    }
    //end of input and declarations    
    while(!vertices.empty()) {
    	it = vertices.begin();
    	//run bfs on normal graph staring from vertex *it
    	fill(status,false);
    	layers.push_back(*it);
    	status[*it] = true ;
	    while(!layers.empty()) {
	    	foo = layers.front();
	        for (int itt = 0; itt < graph[foo].size(); ++itt) {
	            if (status[graph[foo][itt]] == false) {
	                status[graph[foo][itt]] = true;
	                layers.push_back(graph[foo][itt]);
	            }
	        }
	        layers.pop_front();
	    }
    	//run bfs on reverse graph starting from vertex *it
    	fill(rstatus,false);
    	layers.push_back(*it);
    	rstatus[*it] = true ;
	    while(!layers.empty()) {
	    	foo = layers.front();
	        for (int itt = 0; itt < rgraph[foo].size(); ++itt) {
	            if (rstatus[rgraph[foo][itt]] == false) {
	                rstatus[rgraph[foo][itt]] = true;
	                layers.push_back(rgraph[foo][itt]);
	            }
	        }
	        layers.pop_front();
	    }
    	//check for the intersection of verties from above two sets and add the set to the result
    	for (int i = 1; i <= V; ++i) {
    		if(status[i] == true && rstatus[i] == true) {
    			temp.push_back(i);
    			vertices.erase(i);
    		}
    	}
    	components.push_back(temp);
    	temp.clear();
    }
    printf("\n\nThe connected components are:\n");
    for (int i = 0; i < components.size(); ++i) {
    	for (int j = 0; j < components[i].size(); ++j) {
    		printf("%d<->",components[i][j]);
    	}
    	printf("\n");
    }
    return 0;
}