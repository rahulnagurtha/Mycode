#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;


struct tree {
	pair<int,int> left;
	pair<int,int> right;
	pair<int,int> highest;
};

tree part[500005];

int arr[100005];

/*
****the indexing can be from [0,n-1] or [1,n]
****based on the type pass the necessary arguments
****for example if [0,n-1] update(1,x,0,n-1,y) 
				if [1,n] update(1,x,1,n,y);
*/



// Build and init tree with array [i,j]

void build(int node,int i,int j,int status) {

	if(i>j) return;		 // invalid range to build
	if(i==j) {						
		part[node].left.FF = arr[i];			// Leaf nodes initialisation
		part[node].left.SS = 1;
		part[node].right.FF = arr[i];
		part[node].right.SS = 1;
		part[node].highest.FF = arr[i];
		part[node].highest.SS = 1;
		return;
	}

	build(node*2,i,(i+j)/2,0);	// Init left child
	build(node*2+1,1+(i+j)/2,j,1);	// Init right child

	//update the node based on the values of left and right nodes
	
	//fixing left side info
	if(arr[i] == arr[(i+j)/2] && arr[(i+j)/2] == arr[1+(i+j)/2]) {
		part[node].left.FF = part[node*2].left.FF;
		part[node].left.SS = part[node*2].left.SS + part[1+2*node].left.SS;
	}
	else {
		part[node].left.FF = part[node*2].left.FF;
		part[node].left.SS = part[node*2].left.SS;
	}
	//fixing right side info
	if(arr[j] == arr[1+(i+j)/2] && arr[(i+j)/2] == arr[1+(i+j)/2]) {
		part[node].right.FF = part[1+node*2].right.FF;
		part[node].right.SS = part[node*2].right.SS + part[1+2*node].right.SS;
	}
	else {
		part[node].right.FF = part[1+node*2].right.FF;
		part[node].right.SS = part[1+node*2].right.SS;
	}
	//fixing highest info
	if(arr[(i+j)/2] == arr[1+(i+j)/2]) {
		if(part[2*node].right.SS + part[1+2*node].left.SS >= part[2*node].highest.SS && part[2*node].right.SS + part[1+2*node].left.SS >= part[1+2*node].highest.SS) {
			if(part[2*node].highest.SS == part[1+2*node].highest.SS && part[2*node].right.SS + part[1+2*node].left.SS == part[1+2*node].highest.SS) {
				if(status == 1){
					part[node].highest.SS = part[2*node].highest.SS;
					part[node].highest.FF = part[2*node].highest.FF;
				}
				else if(status == 0) {
					part[node].highest.SS = part[1+2*node].highest.SS;
					part[node].highest.FF = part[1+2*node].highest.FF;
				}
				else {
					part[node].highest.SS = part[2*node].right.SS + part[1+2*node].left.SS;
					part[node].highest.FF = arr[(i+j)/2];
				}
			}
			else if(part[2*node].highest.SS == part[2*node].right.SS + part[1+2*node].left.SS) {
				if(status == 1){
					part[node].highest.SS = part[2*node].highest.SS;
					part[node].highest.FF = part[2*node].highest.FF;
				}
				else {
					part[node].highest.SS = part[2*node].right.SS + part[1+2*node].left.SS;
					part[node].highest.FF = arr[(i+j)/2];
				}
			}
			else if(part[2*node].right.SS + part[1+2*node].left.SS == part[1+2*node].highest.SS) {
				if(status == 1){
					part[node].highest.SS = part[2*node].highest.SS;
					part[node].highest.FF = part[2*node].highest.FF;
				}
				else {
					part[node].highest.SS = part[2*node].right.SS + part[1+2*node].left.SS;
					part[node].highest.FF = arr[(i+j)/2];
				}
			}
			else {
				part[node].highest.SS = part[2*node].right.SS + part[1+2*node].left.SS;
				part[node].highest.FF = arr[(i+j)/2];
			}
		}
		else if(part[2*node].right.SS + part[1+2*node].left.SS <= part[2*node].highest.SS && part[2*node].highest.SS >= part[1+2*node].highest.SS) {
			if(part[2*node].highest.SS == part[1+2*node].highest.SS) {
				if(status == 1){
					part[node].highest.SS = part[2*node].highest.SS;
					part[node].highest.FF = part[2*node].highest.FF;
				}
				else if(status == 0) {
					part[node].highest.SS = part[1+2*node].highest.SS;
					part[node].highest.FF = part[1+2*node].highest.FF;
				}
				else {
					part[node].highest.SS = part[2*node].highest.SS;
					part[node].highest.FF = part[2*node].highest.FF;
				}
			}
			else {
				part[node].highest.SS = part[2*node].highest.SS;
				part[node].highest.FF = part[2*node].highest.FF;
			}
		}
		else {
			if(part[2*node].highest.SS == part[1+2*node].highest.SS) {
				if(status == 0) {
					part[node].highest.SS = part[1+2*node].highest.SS;
					part[node].highest.FF = part[1+2*node].highest.FF;
				}
				else if(status == 1) {
					part[node].highest.SS = part[2*node].highest.SS;
					part[node].highest.FF = part[2*node].highest.FF;
				}
				else {
					part[node].highest.SS = part[1+2*node].highest.SS;
					part[node].highest.FF = part[1+2*node].highest.FF;
				}
			}
			else {
				part[node].highest.SS = part[1+2*node].highest.SS;
				part[node].highest.FF = part[1+2*node].highest.FF;
			}
		}
	}
	else {
		if(part[2*node].highest.SS > part[1+2*node].highest.SS) {
			part[node].highest.SS = part[2*node].highest.SS;
			part[node].highest.FF = part[2*node].highest.FF;
		}
		else if(part[2*node].highest.SS == part[1+2*node].highest.SS) {
			if(status == 1) {
				part[node].highest.SS = part[2*node].highest.SS;
				part[node].highest.FF = part[2*node].highest.FF;
			}
			else if(status == 0) {
				part[node].highest.SS = part[1+2*node].highest.SS;
				part[node].highest.FF = part[1+2*node].highest.FF;
			}
			else {
				part[node].highest.SS = part[1+2*node].highest.SS;
				part[node].highest.FF = part[1+2*node].highest.FF;
			}
		}
		else {
			part[node].highest.SS = part[1+2*node].highest.SS;
			part[node].highest.FF = part[1+2*node].highest.FF;
		}

	}
	// printf("for %d-%d:\n",i,j);
	// printf("highest:%d,%d times\n",part[node].highest.FF,part[node].highest.SS);
	// printf("left:%d,%d times\n",part[node].left.FF,part[node].left.SS);
	// printf("right:%d,%d times\n",part[node].right.FF,part[node].right.SS);
	// printf("\n\n");
	return;
}

/** 
 ** Query tree to get sum within range [i, j]
 **/

PII query_sum(int node,int a,int b,int i,int j) {
	if(a > b || a > j || b < i) return mp(0,-10);	//invalid segment
	if(a >= i && b <= j) return mp(part[node].highest.FF,part[node].highest.SS);	//Current segment is totally within range [i, j]

	PII q1,q2;

	q1 = query_sum(node*2, a, (a+b)/2, i, j);	//query left child
	q2 = query_sum(1+node*2, 1+(a+b)/2, b, i, j); //query right child
	// printf("query from %d-%d\n",a,(a+b)/2);
	// printf("%d,%d times\n",q1.FF,q1.SS);
	// printf("\n\n");
	// printf("query from %d-%d\n",1+(a+b)/2,b);
	// printf("%d,%d times\n",q2.FF,q2.SS);
	// printf("\n\n");
	PII res;
	if(q1.FF == q2.FF) {
		res.FF = q1.FF;
		res.SS = q1.SS + q2.SS;
	}
	else if(q1.SS > q2.SS) {
		res.FF = q1.FF;
		res.SS = q1.SS;
	}
	else {
		res.FF = q2.FF;
		res.SS = q2.SS;	//return the final result based on left and right child
	}
	return res;
}



// main code begins now

int main()
{
    int n,q,a,b;
    // freopen("in.txt", "r", stdin);
    // cin >> t ;
    while(1) {
    	scanf("%d",&n);
    	if(n == 0) break;
    	scanf("%d",&q);
    	for (int i = 1; i <= n; ++i) {
    		scanf("%d",&arr[i]);
    	}
    	build(1,1,n,2);
    	for (int i = 0; i < q; ++i) {
    		scanf("%d %d",&a,&b);
    		a = query_sum(1,1,n,a,b).SS;
    		printf("%d\n",a);
    	}
    }
    return 0;
}