#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a%b<0)?(((a%b)+b)%b):(a%b))
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
    stringstream ss;
    int foo,k;
    string inp;
    int number,parent[100],cycle=0;
    fill(parent,-1);
    freopen("in.txt", "r", stdin);
    vector<list<int> > graph(100);
    deque<int> layers;
    bool status[100];
    cin >> number ;
    for (int j = 1; j <=number ; ++j) {
        status[j]=false;
    }
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
    //end of declaration and input


    printf("\n");
    printf("starting node: \n");
    cin >> foo ;
    layers.push_back(foo);
    
    //start of bfs
    while(!layers.empty()) {
        foo = layers.front();
        for (list<int>::iterator it=graph[foo].begin(); it!= graph[foo].end(); ++it) {
            if (status[*it]==false) {
                status[*it]=true;
                parent[*it]=foo;
                layers.push_back(*it);
            }
            else {
                if(parent[foo]!=*it) cycle=1;
            }
        }
        layers.pop_front();
    }
    //end of bfs

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