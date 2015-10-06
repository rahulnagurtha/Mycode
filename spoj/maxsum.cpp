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
#define rem1(a,b) 			    ((a%b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;


struct tree {
	LL ma;
	LL pos;
};

tree part[500001];

LL arr[100001];

/*
****the indexing can be from [0,n-1] or [1,n]
****based on the type pass the necessary arguments
****for example if [0,n-1] update(1,x,0,n-1,y) 
				if [1,n] update(1,x,1,n,y);
*/



// Build and init tree with array [i,j]

void build(LL node,LL i,LL j) {

	if(i>j) return;		 // invalid range to build
	if(i==j) {						
		part[node].ma=arr[i];			// Leaf nodes initialisation
		part[node].pos=i;
		return;
	}

	build(node*2,i,(i+j)/2);	// Init left child
	build(node*2+1,1+(i+j)/2,j);	// Init right child

	//update the node based on the values of left and right nodes
	part[node].ma=max(part[node*2].ma,part[1+node*2].ma);
	part[node].pos=( (part[node*2].ma > part[1+node*2].ma) ? (part[node*2].pos) : (part[1+node*2].pos) );
	return;
}




/**
 * Query tree to get max element value within range [i, j]
 */

struct tree query_max(LL node,LL a,LL b,LL i,LL j) {

	if(a > b || a > j || b < i) { 
		struct tree garbage;
		garbage.ma=-2147483645;
		garbage.pos=-1;
		return garbage;	//invalid segment
	}
	if(a >= i && b <= j) return part[node];	// Current segment is totally within range [i, j]

	struct tree q1,q2,tobesent;

	q1=query_max(node*2, a, (a+b)/2, i, j);	//query the left child
	q2=query_max(1+node*2, 1+(a+b)/2, b, i, j);	//query the right child
	
	if(q1.ma > q2.ma) {
		// printf("%lld > %lld\n",q1.ma,q2.ma);
		tobesent.ma = q1.ma;
		tobesent.pos = q1.pos;
	}
	else tobesent = q2;
	return tobesent;
}




/**
 * update the pos indexed element in [i, j] with value val
 */

void update(LL node,LL pos,LL i,LL j,LL val) {
    if(i>j) return;	//invalid segment
    if(i==j&&i==pos) {			
        part[node].ma=val;		//update the leaf node
        return;
    }
    if(i<=pos&&j>=pos) {
        update(2*node,pos,i,(i+j)/2,val);	//update left child
        update(2*node+1,pos,(i+j)/2 + 1,j,val);	//update right child
        part[node].ma=max(part[2*node].ma,part[2*node+1].ma);
        part[node].pos=( (part[node*2].ma > part[2*node+1].ma) ? (part[node*2].pos) : (part[1+node*2].pos) );
    	return;
    }
}


// main code begins now

int main()
{
    // freopen("in.txt", "r", stdin);
	LL n,x,y,q,ans,back;
	struct tree temp;
	char ch;
	scanf("%lld",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld",&arr[i]);		
	}
    build(1,1,n);
    scanf("%lld",&q);
    getchar();
    for (int i = 0; i < q; ++i) {
    	// printf("value is %d\n",i);
		// scanf( "%*c%c%lld%lld",&ch,&x,&y);
    	// getchar();
    	ch=getchar();
    	scanf("%lld%lld",&x,&y);
		getchar();
		if (ch == 'Q') {
			temp=query_max(1,1,n,x,y);
			ans=temp.ma;
			// printf("first highest is %lld at %lld\n",ans,temp.pos);
			back=temp.pos;
			update(1,temp.pos,1,n,-1);
			temp=query_max(1,1,n,x,y);
			// printf("second highest is %lld at %lld\n",temp.ma,temp.pos);
			ans+=temp.ma;
			update(1,back,1,n,ans-temp.ma);
			printf("%lld\n",ans);
		}
		else {
			update(1,x,1,n,y);
		}
    }
    return 0;
}