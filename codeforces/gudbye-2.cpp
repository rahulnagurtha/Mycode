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
#define rem1(a,b)               ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


VOVI graph(305);
bool ostatus[305],status[305];
deque<int> layers;
int N,numbers[305],pre;
string inp;
VI temp,temp1;

// main code begins now

int main()
{
    fill(ostatus,false);
    fill(status,false);
    freopen("in.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> numbers[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> inp;
        for (int j = 0; j < inp.size(); ++j) {
            if(inp[j] == '1') graph[i].pb(j+1);
        }
    }
    //run bfs multiple times
    for (int i = 1; i <= N; ++i) {
        if(ostatus[i] == true) continue;
        // printf("starting at %d\n",i);
        fill(status,false);
        layers.pb(i);
        ostatus[i] = true;
        status[i] = true;
        while(!layers.empty()) {
            pre = layers.front();
            for (int j = 0; j < graph[pre].size(); ++j) {
                if(status[graph[pre][j]] == false) {
                    status[graph[pre][j]] = true;
                    ostatus[graph[pre][j]] = true;
                    layers.pb(graph[pre][j]);
                }
            }
            layers.pop_front();
        }
        for (int j = 1; j <= N; ++j) {
            if(status[j] == true) {
                temp.pb(j);
            }
        }
        for (int j = 0; j < temp.size(); ++j) {
            temp1.pb(numbers[temp[j]]);
        }
        sort(temp1.begin(),temp1.end());
        for (int j = 0; j < temp.size(); ++j) {
            numbers[temp[j]] = temp1[j];
        }
        temp.clear();
        temp1.clear();
    }
    for (int i = 1; i <= N; ++i) {
        printf("%d ",numbers[i]);
    }
    return 0;
}