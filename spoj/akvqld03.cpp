#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

struct tree {
	LL sum;
};

tree part[5000005];

LL arr[1000005];

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
		// part[node].mi=arr[i];			// Leaf nodes initialisation
		// part[node].ma=arr[i];
		part[node].sum=arr[i];
		return;
	}

	build(node*2,i,(i+j)/2);	// Init left child
	build(node*2+1,1+(i+j)/2,j);	// Init right child

	//update the node based on the values of left and right nodes
	// part[node].ma=max(part[node*2].ma,part[1+node*2].ma);
	// part[node].mi=min(part[node*2].mi,part[1+node*2].mi);
	part[node].sum=part[node*2].sum+part[1+node*2].sum;
	return;
}


/**
 * Query tree to get sum within range [i, j]
 */
LL query_sum(LL node,LL a,LL b,LL i,LL j) {
	if(a > b || a > j || b < i) return 0;	//invalid segment
	if(a >= i && b <= j) return part[node].sum;	//Current segment is totally within range [i, j]

	LL q1,q2;

	q1=query_sum(node*2, a, (a+b)/2, i, j);	//query left child
	q2=query_sum(1+node*2, 1+(a+b)/2, b, i, j); //query right child
	
	LL res = q1+q2;	//return the final result based on left and right child
	
	return res;
}


/**
 * update the pos indexed element in [i, j] with value val
 */

void update(LL node,LL pos,LL i,LL j,LL val) {
    if(i>j) return;	//invalid segment

    if(i==j&&i==pos) {			
        // part[node].ma=val;
        // part[node].mi=val;		//update the leaf node
        part[node].sum += val;
        return;
    }

    if(i<=pos&&j>=pos) {
        update(2*node,pos,i,(i+j)/2,val);	//update left child
        update(2*node+1,pos,(i+j)/2 + 1,j,val);	//update right child
        // part[node].ma=max(part[2*node].ma,part[2*node+1].ma);
        // part[node].mi=min(part[2*node].mi,part[2*node+1].mi);	//update the nodes
        part[node].sum=part[2*node].sum+part[1+2*node].sum;
    	return;
    }
}


// main code begins now

int main()
{
    LL n,q,A,B;
    string typeq;
    scanf("%lld %lld",&n,&q);
    for (LL i = 0; i < q; ++i) {
    	cin >> typeq >> A >> B ;
    	if(typeq[0] == 'a') {
    		update(1,A,1,n,B);
    	}
    	else {
    		printf("%lld\n",query_sum(1,1,n,A,B));
    	}
    }
    return 0;
}