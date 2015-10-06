#include <bits/stdc++.h>

using namespace std;


typedef long long int LL;


struct tree {
	LL mi;
};

tree part[500002];

LL arr[100005];


// Build and init tree with array [i,j]

void build(LL node,LL i,LL j) {

	if(i>j) return;		 // invalid range to build
	if(i==j) {						
		part[node].mi=arr[i];			// Leaf nodes initialisation
		return;
	}

	build(node*2,i,(i+j)/2);	// Init left child
	build(node*2+1,1+(i+j)/2,j);	// Init right child

	//update the node based on the values of left and right nodes
	part[node].mi=min(part[node*2].mi,part[1+node*2].mi);
	return;
}




/**
 * Query tree to get min element value within range [i, j]
 */

LL query_min(LL node,LL a,LL b,LL i,LL j) {

	if(a > b || a > j || b < i) return 2147483645000;	//invalid segment
	if(a >= i && b <= j) return part[node].mi;		// Current segment is totally within range [i, j]
	
	LL q1,q2;

	q1=query_min(node*2, a, (a+b)/2, i, j);	//query the left child
	q2=query_min(1+node*2, 1+(a+b)/2, b, i, j); //query the right child
	
	LL res = min(q1, q2); //return the final result based on left and right child
	
	return res;
}


// main code begins now

int main()
{
    LL t,n,q,num = 1,a,b;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	scanf("%lld %lld",&n,&q);
    	for (LL i = 1; i <= n; ++i) {
    		scanf("%lld",&arr[i]);
    	}
    	build(1,1,n);
    	printf("Scenario #%lld:\n\n",num);
    	for (LL i = 0; i < q; ++i) {
    		scanf("%lld %lld",&a,&b);
    		printf("%lld\n",query_min(1,1,n,a,b));
    	}
    	num++;
    }
    return 0;
}