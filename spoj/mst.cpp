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


int V,E,in,out,weight,n,node,tobereturned;
LL ans;
bool status[10005];
int pos[10005];
int A[10005];
int key[10005];
vector<vector<PII> > graph(10005);


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
    fill(status,false);
    scanf("%d %d",&V,&E);
    n = V;
    for (int i = 0; i < E; ++i) {
    	scanf("%d %d %d",&out,&in,&weight);
    	graph[out].pb(mp(in,weight));
    	graph[in].pb(mp(out,weight));
    }
    A[1] = 0;
    pos[1] = 1;
    key[1] = 1;
    for (int i = 2; i <= V; ++i) {
    	A[i] = 100000007;
    	key[i] = i;
    	pos[i] = i;
    }
    buildheap();
    for (int i = 0; i < V; ++i) {
    	node = extractmax();
    	ans += (LL)A[pos[node]];
    	status[node] = true;
    	for (int j = 0; j < graph[node].size(); ++j) {
    		if(status[graph[node][j].FF] == false && graph[node][j].SS < A[pos[graph[node][j].FF]]) {
    			decreasekey(pos[graph[node][j].FF],graph[node][j].SS);
    		}
    	}
    }
    printf("%lld\n",ans);
    return 0;
}