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


stringstream ss;
int foo,k,temp,cycle=0;
string inp;
int number;
vector<list<int> > graph(100);
deque<int> storage;
bool status[100];
int parent[100];


// main code begins now

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> number ;
    for (int j = 1; j <=number ; ++j) {
    	status[j]=false;
    }
    fill(parent,-1);
    getchar();
	k=1;

	while (k<=number) {
		getline (cin, inp);
		ss.clear ();
		ss.str ("");
		ss << inp;
		while (ss >> foo) {
			graph[k].push_back(foo);
		}
		k++;
	}
	printf("\n");
    printf("starting node: \n");
    cin >> foo ;
    storage.push_back(foo);

    //dfs iteration
    while(!storage.empty()) {
    	temp=storage.front();
    	storage.pop_front();
    	if (status[temp]==false) {
    		status[temp]=true;
    		for (list<int>::iterator it = graph[temp].begin(); it!=graph[temp].end() ; ++it) {
				if (status[*it]==false) {
                    storage.push_front(*it);
                    parent[*it]=temp;
                }
                else {
                    if(parent[temp]!=*it) {
                        cycle=1;
                    }
                }
			}
    	}
    }
    //dfs complete

	printf("reachable nodes are:\n");
    for (int i = 1; i <=number ; ++i) {
    	if (status[i]==true) {
    		printf("%d->",i);
    	}
    }
    printf("\n");
    if(cycle!=0) printf("yes there is a cycle in the graph\n");
    else printf("there is no cycle in the graph\n");
    return 0;
}