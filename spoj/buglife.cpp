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
	int t,count = 1;
	cin >> t ;
	while(t--) {
	    //declaration and input
		int foo,k;
	    int V,E,in,out,curcolor,flag=0;
	    int colour[1005];
	    vector<vector<int> > graph(1005);
	    deque<int> layers;
	    bool status[1005];
	    scanf("%d %d",&V,&E);
	    for (int j = 1; j <= V ; ++j) {
	    	status[j] = false;
	    	colour[j] = -1 ;
	    }
		for (int i = 0; i < E; ++i) {
	        scanf("%d %d",&out,&in);
	        graph[out].push_back(in);
	        graph[in].push_back(out);
	    }
	    for (int i = 1; i <= V ; ++i)
	    {
	    	if(status[i] == true) continue;
		    foo = i ;
		    colour[foo] = 0;
		    layers.push_back(foo);
		    while(!layers.empty()) {
		    	foo = layers.front();
		    	curcolor = colour[foo];
		        for (int it = 0; it < graph[foo].size(); ++it) {
		            if (status[graph[foo][it]] == false) {
		                status[graph[foo][it]] = true;
		                colour[graph[foo][it]] = (curcolor+1)%2;
		                layers.push_back(graph[foo][it]);
		            }
		        }
		        layers.pop_front();
		    }
		}
		for (int i = 1; i <=V; ++i) {
			for (int j = 0; j < graph[i].size(); ++j) {
				if(colour[i] == colour[graph[i][j]]) {
					flag = 1;
					break;
				}
			}
		}
		printf("Scenario #%d:\n",count);
		count++;
		if(flag == 0) printf("No suspicious bugs found!\n");
		else printf("Suspicious bugs found!\n");
	}
    return 0;
}