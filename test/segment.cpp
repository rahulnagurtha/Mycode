#include <bits/stdc++.h>

using namespace std;


struct tree {
	int mi;
	int ma;
	int sum;
};

tree part[500001];

int arr[100001];

/*
****the indexing can be from [0,n-1] or [1,n]
****based on the type pass the necessary arguments
****for example if [0,n-1] update(1,x,0,n-1,y) 
				if [1,n] update(1,x,1,n,y);
*/



// Build and init tree with array [i,j]

void build(int node,int i,int j) {

	if(i>j) return;		 // invalid range to build
	if(i==j) {						
		part[node].mi=arr[i];			// Leaf nodes initialisation
		part[node].ma=arr[i];
		part[node].sum=arr[i];
		return;
	}

	build(node*2,i,(i+j)/2);	// Init left child
	build(node*2+1,1+(i+j)/2,j);	// Init right child

	//update the node based on the values of left and right nodes
	part[node].ma=max(part[node*2].ma,part[1+node*2].ma);
	part[node].mi=min(part[node*2].mi,part[1+node*2].mi);
	part[node].sum=part[node*2].sum+part[1+node*2].sum;
	return;
}




/**
 * Query tree to get min element value within range [i, j]
 */

int query_min(int node,int a,int b,int i,int j) {

	if(a > b || a > j || b < i) return 2147483645;	//invalid segment
	if(a >= i && b <= j) return part[node].mi;		// Current segment is totally within range [i, j]
	
	int q1,q2;

	q1=query_min(node*2, a, (a+b)/2, i, j);	//query the left child
	q2=query_min(1+node*2, 1+(a+b)/2, b, i, j); //query the right child
	
	int res = min(q1, q2); //return the final result based on left and right child
	
	return res;
}




/**
 * Query tree to get max element value within range [i, j]
 */

int query_max(int node,int a,int b,int i,int j) {

	if(a > b || a > j || b < i) return -2147483645;	//invalid segment
	
	if(a >= i && b <= j) return part[node].ma;	// Current segment is totally within range [i, j]

	int q1,q2;

	q1=query_max(node*2, a, (a+b)/2, i, j);	//query the left child
	q2=query_max(1+node*2, 1+(a+b)/2, b, i, j);	//query the right child
	
	int res = max(q1, q2);	//return the final result based on left and right child
	
	return res;
}




/**
 * Query tree to get sum within range [i, j]
 */
int query_sum(int node,int a,int b,int i,int j) {
	if(a > b || a > j || b < i) return 0;	//invalid segment
	if(a >= i && b <= j) return part[node].sum;	//Current segment is totally within range [i, j]

	int q1,q2;

	q1=query_sum(node*2, a, (a+b)/2, i, j);	//query left child
	q2=query_sum(1+node*2, 1+(a+b)/2, b, i, j); //query right child
	
	int res = q1+q2;	//return the final result based on left and right child
	
	return res;
}


/**
 * update the pos indexed element in [i, j] with value val
 */

void update(int node,int pos,int i,int j,int val) {
    if(i>j) return;	//invalid segment

    if(i==j&&i==pos) {			
        part[node].ma=val;
        part[node].mi=val;		//update the leaf node
        part[node].sum=val;
        return;
    }

    if(i<=pos&&j>=pos) {
        update(2*node,pos,i,(i+j)/2,val);	//update left child
        update(2*node+1,pos,(i+j)/2 + 1,j,val);	//update right child
        part[node].ma=max(part[2*node].ma,part[2*node+1].ma);
        part[node].mi=min(part[2*node].mi,part[2*node+1].mi);	//update the nodes
        part[node].sum=part[2*node].sum+part[1+2*node].sum;
    	return;
    }
}

void update_range(int node,int a,int b,int i,int j,int val) {
	if(a > b || a > j || b < i) return;	//invalid segment
	if(a==b && a<=j && a>=i) {
		part[node].ma=val;
        part[node].mi=val;		//update the leaf node
        part[node].sum=val;
        return;
	}
	update_range(2*node,a,(a+b)/2,i,j,val);
	update_range(2*node+1,1+(a+b)/2,b,i,j,val);

	part[node].ma=max(part[2*node].ma,part[2*node+1].ma);
    part[node].mi=min(part[2*node].mi,part[2*node+1].mi);	//update the nodes
    part[node].sum=part[2*node].sum+part[1+2*node].sum;
    return;

}



// main code begins now

int main()
{
    int t,n,left,right,pos,val;
    char option;
    // freopen("in.txt", "r", stdin);
    cin >> n ;
    for (int i = 1; i <= n ; ++i) {
    	cin >> arr[i];
    }
    build(1,1,n);
    cin >> t ;
    while(t--) {
    	printf("enter the option:\n\n");
    	cin >> option ;
    	if(option=='m') {
    		printf("enter positions\n\n");
    		cin >> left >> right ;
    		cout << query_min(1,1,n,left,right) << endl ;
    	}
    	else if(option=='M') {
    		printf("enter positions\n\n");
    		cin >> left >> right ;
    		cout << query_max(1,1,n,left,right) << endl ;
    	}
    	else if(option=='s') {
    		printf("enter positions\n\n");
    		cin >> left >> right ;
    		cout << query_sum(1,1,n,left,right) << endl ;
    	}
    	else if(option=='u') {
    		printf("enter positions\n\n");
    		cin >> pos >> val ;
    		arr[pos]=val;
    		update(1,pos,1,n,val);
    	}
    	else if(option=='U') {
    		printf("enter positions\n\n");
    		cin >> left >> right >> val ;
    		for (int i = left; i <=right ; ++i) {
    			arr[i]=val;
    		}
    		update_range(1,1,n,left,right,val);
    	}
    	else {
    		for (int i = 1; i <= n; ++i) {
    			cout << arr[i] << " " ;
    		}
    		printf("\n");
    	}

    }
    return 0;
}
