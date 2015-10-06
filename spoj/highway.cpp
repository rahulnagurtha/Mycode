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


int V,E,in,out,weight,n,node,tobereturned,start,ending;
LL ans;
bool status[100005];     //status[i] denotest the status of ith node
int pos[100005];         //pos[i] contains the index of ith node in the heap array
LL A[100005];           //A[i] contains the value of ith node in the heap array
int key[100005];         //key[i] contains the node number of ith element in the heap array



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

void decreasekey(int position,int value) {
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

// main code begins now

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        vector<vector<PLL> > graph(100005);
        int flag;
        fill(status,false);
        scanf("%d %d %d %d",&V,&E,&start,&ending);
        n = V;
        for (int i = 0; i < E; ++i) {
            scanf("%d %d %d",&out,&in,&weight);
            graph[out].pb(mp(in,weight));
            graph[in].pb(mp(out,weight));
        }
        // scanf("%d %d",&start,&ending);
        for (int i = 1; i <= V; ++i) {
            A[i] = 100000007;
            key[i] = i;
            pos[i] = i;
        }
        A[start] = 0;
        pos[start] = start;
        key[start] = start;
        status[start] = true;
        buildheap();
        for (int i = 0; i < V; ++i) {
            node = extractmax();
            flag = 0;
            for (int j = 0; j < graph[node].size(); ++j) {
                status[node] = true;
                flag = 1;
                if(status[graph[node][j].FF] == false && graph[node][j].SS + A[pos[node]] < A[pos[graph[node][j].FF]]) {
                    decreasekey(pos[graph[node][j].FF],graph[node][j].SS + A[pos[node]]);
                }
            }
            if(flag == 0) break;
        }
        if(status[ending] == false) printf("NONE\n");
        else {
            printf("%lld\n",A[pos[ending]]);
        }
    }
    return 0;
}