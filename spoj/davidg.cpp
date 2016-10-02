#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define N                       200005
#define INFFF                   1000000000007
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;


int V,E,n,node,tobereturned,start,ending;
double temp;
LL ans,weight,p,in,out;
bool status[N];     //status[i] denotest the status of ith node
int pos[N];         //pos[i] contains the index of ith node in the heap array
LL A[N];           //A[i] contains the value of ith node in the heap array
int key[N];         //key[i] contains the node number of ith element in the heap array


void heapify(int position,int last) {
    int left,right,smallest;
    smallest = position;
    left = position*2;
    right = 1 + position*2;
    if(A[left] < A[position] && left <= last) {
        smallest = left;
    }
    if(A[right] < A[smallest] && right <= last) {
        smallest = right;
    }
    swap(A[position],A[smallest]);
    swap(key[position],key[smallest]);
    swap(pos[key[position]],pos[key[smallest]]);
    if(smallest != position && smallest <= last) heapify(smallest,last);
    else return;
}

void buildheap() {
    for (int i = n/2; i >= 1; --i) {
        heapify(i,n);
    }
}

void upheapify(int position) {
    int parent = position/2;
    if(A[parent] > A[position]) {
        swap(A[position],A[parent]);
        swap(key[position],key[parent]);
        swap(pos[key[position]],pos[key[parent]]);
        if(position != 1) upheapify(parent);
    }
}

void decreasekey(int position,LL value) {
    A[position] = value;
    upheapify(position);
}

int extractmax() {
    tobereturned = key[1];
    swap(A[n],A[1]);
    swap(key[n],key[1]);
    swap(pos[key[n]],pos[key[1]]);
    n--;
    heapify(1,n);
    return tobereturned;
}

void initiate(int ini) {
    for (int i = 1; i <= V; ++i) {
        A[i] = INFFF;
        key[i] = i;
        pos[i] = i;
    }
    A[ini] = 0;
    pos[ini] = ini;
    key[ini] = ini;
    status[ini] = true;
}

// main code begins now

int main()
{
    int t,count;
    cin >> t ;
    count = 1;
    while(t--) {
        vector<vector<pair<int,LL> > > graph(N);
        vector<PLL> points(N);
        LL total = 0;
        LL ans = 0;
        fill(status,false);
        scanf("%d %lld",&V,&p);
        n = V;
        for (int i = 1; i <= V; ++i) {
            scanf("%lld %lld",&out,&in);
            points[i].FF = out;
            points[i].SS = in;
            for (int j = 1; j < i; ++j) {
                temp = sqrt((out-points[j].FF)*(out-points[j].FF)+(in-points[j].SS)*(in-points[j].SS));
                weight = ceil((p)*temp);
                graph[i].pb(mp(j,weight));
                graph[j].pb(mp(i,weight));
            }
        }
        // scanf("%d %d",&start,&ending);
        initiate(1);
        buildheap();
        for (int i = 0; i < V; ++i) {
            node = extractmax();
            status[node] = true;
            ans += A[pos[node]];
            ans = ans % MOD;
            for (int j = 0; j < graph[node].size(); ++j) {
                if(status[graph[node][j].FF] == false && graph[node][j].SS < A[pos[graph[node][j].FF]]) {
                    decreasekey(pos[graph[node][j].FF],graph[node][j].SS);
                }
            }
        }
        // if(status[ending] == false) printf("NO\n");
        printf("Scenario #%d: %lld\n",count,ans);
        count++;
    }
    return 0;
}