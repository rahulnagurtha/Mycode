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
    int t;
    cin >> t ;
    while(t--) {
    	//declaration and input
        vector<VI> components;
        vector<VI> graph(105);
    	vector<VI> rgraph(105);
    	set<int> vertices;
    	deque<int> layers;
        string testing;
    	VI temp;
    	int V,E,in,out,foo;
    	bool status[105],rstatus[105];
    	set<int>::iterator it;
    	// printf("enter number of vertices and edges in same order: \n");
        cin >> V ;
        for (int i = 1; i <= V ; ++i) {
        	vertices.insert(i);
        }
        getchar();
        // printf("enter the edges seperated by a line,each line is of the form 'u v' if the edge is u->v\n");
        for (int j = 1; j <= V; ++j) {
            // printf("%d is now\n",j);
        	// cin >> out >> in ;
            getline(cin,testing);
            for (int i = 0; i < testing.size(); ++i) {
                if(testing[i] == 'Y') {
                    graph[j].push_back(i+1);
                    rgraph[i+1].push_back(j);  
                }
            } 
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
        // printf("\n\nThe connected components are:\n");
        printf("%d\n",components.size());
    }
    return 0;
}