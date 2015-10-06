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
    int foo,V,E,out,in;
    string inp;
    int parent[10005],cycle=0;
    fill(parent,-1);
    // freopen("in.txt", "r", stdin);
    vector<list<int> > graph(10005);
    deque<int> layers;
    bool status[10005];
    scanf("%d %d",&V,&E);
    for (int j = 1; j <= V ; ++j) {
        status[j]=false;
    }

    for (int j = 1; j <= E ; ++j) {
        scanf("%d %d",&out,&in);
        graph[out].push_back(in);
        graph[in].push_back(out);
    }
    if(V != E+1) {
        printf("NO\n");
        return 0;
    }
    //end of declaration and input

    layers.push_back(1);
    status[1] = true;
    //start of bfs
    while(!layers.empty()) {
        foo=layers.front();
        for (list<int>::iterator it=graph[foo].begin(); it!= graph[foo].end(); ++it) {
            if (status[*it]==false) {
                status[*it]=true;
                parent[*it]=foo;
                layers.push_back(*it);
            }
            else {
                if(parent[foo] != *it) {
                    cycle=1;
                    break;
                }
            }
        }
        if (cycle == 1) break;
        layers.pop_front();
    }
    //end of bfs
    for (int i = 1; i <= V ; ++i) {
        if (status[i]==false) {
            cycle = 1;
        }
    }
    if(cycle!=0) printf("NO\n");
    else printf("YES\n");
    return 0;
}