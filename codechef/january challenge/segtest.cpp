#include <bits/stdc++.h>

using namespace std;




typedef long long int ll;


struct tree {
	ll sum;
	ll dp_start[3];
	ll dp_end[3];
	ll start_end[3];
};


tree part[500001];

int a[100005];

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
		part[node].sum=0;			// Leaf nodes initialisation
		if(a[i]%3==0) {
			part[node].dp_start[0]=1;
			part[node].dp_end[0]=1;
			
			part[node].dp_start[1]=0;
			part[node].dp_end[1]=0;
			
			part[node].dp_start[2]=0;
			part[node].dp_end[2]=0;

			part[node].start_end[0]=1;
			part[node].start_end[1]=0;
			part[node].start_end[2]=0;

			part[node].sum=1;
			// printf("set tree[%d]=%d\n",node,part[node].sum);
		}
		else if(a[i]%3==1) {
			part[node].dp_start[0]=0;
			part[node].dp_end[0]=0;
			
			part[node].dp_start[1]=1;
			part[node].dp_end[1]=1;
			
			part[node].dp_start[2]=0;
			part[node].dp_end[2]=0;

			part[node].start_end[0]=0;
			part[node].start_end[1]=1;
			part[node].start_end[2]=0;

			part[node].sum=0;
			// printf("set tree[%d]=%d\n",node,part[node].sum);
		}
		else {
			part[node].dp_start[0]=0;
			part[node].dp_end[0]=0;
			
			part[node].dp_start[1]=0;
			part[node].dp_end[1]=0;
			
			part[node].dp_start[2]=1;
			part[node].dp_end[2]=1;

			part[node].start_end[0]=0;
			part[node].start_end[1]=0;
			part[node].start_end[2]=1;

			part[node].sum=0;
			// printf("set tree[%d]=%d\n",node,part[node].sum);
		}
		return;
	}

	build(node*2,i,(i+j)/2);	// Init left child
	build(node*2+1,1+(i+j)/2,j);	// Init right child
	ll to_be_added;
	
	to_be_added=part[node*2].dp_end[0]*part[1+node*2].dp_start[0];
	to_be_added+=part[node*2].dp_end[1]*part[1+node*2].dp_start[2];
	to_be_added+=part[node*2].dp_end[2]*part[1+node*2].dp_start[1];
	
	//update the node based on the values of left and right nodes
	part[node].sum=part[node*2].sum+part[1+node*2].sum+to_be_added;
	// printf("set tree[%d]=%d\n",node,part[node].sum);
	//starting update
	to_be_added=part[node*2].start_end[0]*part[1+node*2].dp_start[0];
	to_be_added+=part[node*2].start_end[1]*part[1+node*2].dp_start[2];
	to_be_added+=part[node*2].start_end[2]*part[1+node*2].dp_start[1];
	part[node].dp_start[0]=part[node*2].dp_start[0]+to_be_added;

	to_be_added=part[node*2].start_end[0]*part[1+node*2].dp_start[1];
	to_be_added+=part[node*2].start_end[1]*part[1+node*2].dp_start[0];
	to_be_added+=part[node*2].start_end[2]*part[1+node*2].dp_start[2];
	part[node].dp_start[1]=part[node*2].dp_start[1]+to_be_added;

	to_be_added=part[node*2].start_end[0]*part[1+node*2].dp_start[2];
	to_be_added+=part[node*2].start_end[1]*part[1+node*2].dp_start[1];
	to_be_added+=part[node*2].start_end[2]*part[1+node*2].dp_start[0];
	part[node].dp_start[2]=part[node*2].dp_start[2]+to_be_added;

	//ending update
	to_be_added=part[1+node*2].start_end[0]*part[node*2].dp_end[0];
	to_be_added+=part[1+node*2].start_end[1]*part[node*2].dp_end[2];
	to_be_added+=part[1+node*2].start_end[2]*part[node*2].dp_end[1];
	part[node].dp_end[0]=part[1+node*2].dp_end[0]+to_be_added;

	to_be_added=part[1+node*2].start_end[0]*part[node*2].dp_end[1];
	to_be_added+=part[1+node*2].start_end[1]*part[node*2].dp_end[0];
	to_be_added+=part[1+node*2].start_end[2]*part[node*2].dp_end[2];
	part[node].dp_end[1]=part[1+node*2].dp_end[1]+to_be_added;

	to_be_added=part[1+node*2].start_end[0]*part[node*2].dp_end[2];
	to_be_added+=part[1+node*2].start_end[1]*part[node*2].dp_end[1];
	to_be_added+=part[1+node*2].start_end[2]*part[node*2].dp_end[0];
	part[node].dp_end[2]=part[1+node*2].dp_end[2]+to_be_added;

	//update start-end
	to_be_added=part[node*2].start_end[0]*part[1+node*2].start_end[0];
	to_be_added+=part[node*2].start_end[1]*part[1+node*2].start_end[2];
	to_be_added+=part[node*2].start_end[2]*part[1+node*2].start_end[1];
	part[node].start_end[0]=to_be_added;

	to_be_added=part[node*2].start_end[0]*part[1+node*2].start_end[1];
	to_be_added+=part[node*2].start_end[1]*part[1+node*2].start_end[0];
	to_be_added+=part[node*2].start_end[2]*part[1+node*2].start_end[2];
	part[node].start_end[1]=to_be_added;

	to_be_added=part[node*2].start_end[0]*part[1+node*2].start_end[2];
	to_be_added+=part[node*2].start_end[1]*part[1+node*2].start_end[1];
	to_be_added+=part[node*2].start_end[2]*part[1+node*2].start_end[0];
	part[node].start_end[2]=to_be_added;

	return;
}




/**
 * Query tree to get min element value within range [i, j]
 */

struct tree query_min(int node,int a,int b,int i,int j) {
	tree one;
	if(a > b || a > j || b < i) {
		one.sum=-1;	//invalid segment
		one.dp_end[0]=0;
		one.dp_end[1]=0;
		one.dp_end[2]=0;
		one.dp_start[0]=0;
		one.dp_start[1]=0;
		one.dp_start[2]=0;
		one.start_end[0]=0;
		one.start_end[1]=0;
		one.start_end[2]=0;
		return one;
	}
	if(a >= i && b <= j) {
		one.sum=part[node].sum;	//invalid segment
		one.dp_end[0]=part[node].dp_end[0];
		one.dp_end[1]=part[node].dp_end[1];
		one.dp_end[2]=part[node].dp_end[2];
		one.dp_start[0]=part[node].dp_start[0];
		one.dp_start[1]=part[node].dp_start[1];
		one.dp_start[2]=part[node].dp_start[2];
		one.start_end[0]=part[node].start_end[0];
		one.start_end[1]=part[node].start_end[1];
		one.start_end[2]=part[node].start_end[2];
		return one;		// Current segment is totally within range [i, j]
	}

	tree q1,q2,res; 
	
	q1=query_min(node*2, a, (a+b)/2, i, j);	//query the left child
	q2=query_min(1+node*2, 1+(a+b)/2, b, i, j); //query the right child
	
	if(q1.sum==-1) {
		return q2;
	}

	if(q2.sum==-1) {
		return q1;
	}
	
	ll to_be_added;


	to_be_added=q1.dp_end[0]*q2.dp_start[0];
	to_be_added+=q1.dp_end[1]*q2.dp_start[2];
	to_be_added+=q1.dp_end[2]*q2.dp_start[1];
	
	//update the node based on the values of left and right nodes
	res.sum=q1.sum+q2.sum+to_be_added;

	//starting update
	to_be_added=q1.start_end[0]*q2.dp_start[0];
	to_be_added+=q1.start_end[1]*q2.dp_start[2];
	to_be_added+=q1.start_end[2]*q2.dp_start[1];
	res.dp_start[0]=q1.dp_start[0]+to_be_added;

	to_be_added=q1.start_end[0]*q2.dp_start[1];
	to_be_added+=q1.start_end[1]*q2.dp_start[0];
	to_be_added+=q1.start_end[2]*q2.dp_start[2];
	res.dp_start[1]=q1.dp_start[1]+to_be_added;

	to_be_added=q1.start_end[0]*q2.dp_start[2];
	to_be_added+=q1.start_end[1]*q2.dp_start[1];
	to_be_added+=q1.start_end[2]*q2.dp_start[0];
	res.dp_start[2]=q1.dp_start[2]+to_be_added;

	//ending update
	to_be_added=q2.start_end[0]*q1.dp_end[0];
	to_be_added+=q2.start_end[1]*q1.dp_end[2];
	to_be_added+=q2.start_end[2]*q1.dp_end[1];
	res.dp_end[0]=q2.dp_end[0]+to_be_added;

	to_be_added=q2.start_end[0]*q1.dp_end[1];
	to_be_added+=q2.start_end[1]*q1.dp_end[0];
	to_be_added+=q2.start_end[2]*q1.dp_end[2];
	res.dp_end[1]=q2.dp_end[1]+to_be_added;

	to_be_added=q2.start_end[0]*q1.dp_end[2];
	to_be_added+=q2.start_end[1]*q1.dp_end[1];
	to_be_added+=q2.start_end[2]*q1.dp_end[0];
	res.dp_end[2]=q2.dp_end[2]+to_be_added;

	//update start-end
	to_be_added=part[node*2].start_end[0]*part[1+node*2].start_end[0];
	to_be_added+=part[node*2].start_end[1]*part[1+node*2].start_end[2];
	to_be_added+=part[node*2].start_end[2]*part[1+node*2].start_end[1];
	res.start_end[0]=to_be_added;

	to_be_added=part[node*2].start_end[0]*part[1+node*2].start_end[1];
	to_be_added+=part[node*2].start_end[1]*part[1+node*2].start_end[0];
	to_be_added+=part[node*2].start_end[2]*part[1+node*2].start_end[2];
	res.start_end[1]=to_be_added;

	to_be_added=part[node*2].start_end[0]*part[1+node*2].start_end[2];
	to_be_added+=part[node*2].start_end[1]*part[1+node*2].start_end[1];
	to_be_added+=part[node*2].start_end[2]*part[1+node*2].start_end[0];
	res.start_end[2]=to_be_added;


	 //return the final result based on left and right child
	return res;
}




/**
 * update the pos indexed element in [i, j] with value val
 */

void update(int node,int pos,int i,int j,int val) {
    if(i>j) {	//invalid segment
    	return;
    }

    if(i==j&&i==pos) {

    	part[node].sum=0;			// Leaf nodes initialisation
		if(val%3==0) {
			part[node].dp_start[0]=1;
			part[node].dp_end[0]=1;
			
			part[node].dp_start[1]=0;
			part[node].dp_end[1]=0;
			
			part[node].dp_start[2]=0;
			part[node].dp_end[2]=0;

			part[node].start_end[0]=1;
			part[node].start_end[1]=0;
			part[node].start_end[2]=0;

			part[node].sum=1;
			// printf("set tree[%d]=%d\n",node,part[node].sum);
		}
		else if(val%3==1) {
			part[node].dp_start[0]=0;
			part[node].dp_end[0]=0;
			
			part[node].dp_start[1]=1;
			part[node].dp_end[1]=1;
			
			part[node].dp_start[2]=0;
			part[node].dp_end[2]=0;

			part[node].start_end[0]=0;
			part[node].start_end[1]=1;
			part[node].start_end[2]=0;

			part[node].sum=0;
			// printf("set tree[%d]=%d\n",node,part[node].sum);
		}
		else {
			part[node].dp_start[0]=0;
			part[node].dp_end[0]=0;
			
			part[node].dp_start[1]=0;
			part[node].dp_end[1]=0;
			
			part[node].dp_start[2]=1;
			part[node].dp_end[2]=1;

			part[node].start_end[0]=0;
			part[node].start_end[1]=0;
			part[node].start_end[2]=1;

			part[node].sum=0;
			// printf("set tree[%d]=%d\n",node,part[node].sum);
		}
		return;
    }

    if(i<=pos&&j>=pos) {
        update(2*node,pos,i,(i+j)/2,val);	//update left child
        update(2*node+1,pos,(i+j)/2 + 1,j,val);	//update right child

        ll to_be_added;
		to_be_added=part[node*2].dp_end[0]*part[1+node*2].dp_start[0];
		to_be_added+=part[node*2].dp_end[1]*part[1+node*2].dp_start[2];
		to_be_added+=part[node*2].dp_end[2]*part[1+node*2].dp_start[1];
		
		
		part[node].sum=part[node*2].sum+part[1+node*2].sum+to_be_added;
		// printf("set tree[%d]=%d\n",node,part[node].sum);
		//starting update
		to_be_added=part[node*2].start_end[0]*part[1+node*2].dp_start[0];
		to_be_added+=part[node*2].start_end[1]*part[1+node*2].dp_start[2];
		to_be_added+=part[node*2].start_end[2]*part[1+node*2].dp_start[1];
		part[node].dp_start[0]=part[node*2].dp_start[0]+to_be_added;

		to_be_added=part[node*2].start_end[0]*part[1+node*2].dp_start[1];
		to_be_added+=part[node*2].start_end[1]*part[1+node*2].dp_start[0];
		to_be_added+=part[node*2].start_end[2]*part[1+node*2].dp_start[2];
		part[node].dp_start[1]=part[node*2].dp_start[1]+to_be_added;

		to_be_added=part[node*2].start_end[0]*part[1+node*2].dp_start[2];
		to_be_added+=part[node*2].start_end[1]*part[1+node*2].dp_start[1];
		to_be_added+=part[node*2].start_end[2]*part[1+node*2].dp_start[0];
		part[node].dp_start[2]=part[node*2].dp_start[2]+to_be_added;

		//ending update
		to_be_added=part[1+node*2].start_end[0]*part[node*2].dp_end[0];
		to_be_added+=part[1+node*2].start_end[1]*part[node*2].dp_end[2];
		to_be_added+=part[1+node*2].start_end[2]*part[node*2].dp_end[1];
		part[node].dp_end[0]=part[1+node*2].dp_end[0]+to_be_added;

		to_be_added=part[1+node*2].start_end[0]*part[node*2].dp_end[1];
		to_be_added+=part[1+node*2].start_end[1]*part[node*2].dp_end[0];
		to_be_added+=part[1+node*2].start_end[2]*part[node*2].dp_end[2];
		part[node].dp_end[1]=part[1+node*2].dp_end[1]+to_be_added;

		to_be_added=part[1+node*2].start_end[0]*part[node*2].dp_end[2];
		to_be_added+=part[1+node*2].start_end[1]*part[node*2].dp_end[1];
		to_be_added+=part[1+node*2].start_end[2]*part[node*2].dp_end[0];
		part[node].dp_end[2]=part[1+node*2].dp_end[2]+to_be_added;

		//update start-end
		to_be_added=part[node*2].start_end[0]*part[1+node*2].start_end[0];
		to_be_added+=part[node*2].start_end[1]*part[1+node*2].start_end[2];
		to_be_added+=part[node*2].start_end[2]*part[1+node*2].start_end[1];
		part[node].start_end[0]=to_be_added;

		to_be_added=part[node*2].start_end[0]*part[1+node*2].start_end[1];
		to_be_added+=part[node*2].start_end[1]*part[1+node*2].start_end[0];
		to_be_added+=part[node*2].start_end[2]*part[1+node*2].start_end[2];
		part[node].start_end[1]=to_be_added;

		to_be_added=part[node*2].start_end[0]*part[1+node*2].start_end[2];
		to_be_added+=part[node*2].start_end[1]*part[1+node*2].start_end[1];
		to_be_added+=part[node*2].start_end[2]*part[1+node*2].start_end[0];
		part[node].start_end[2]=to_be_added;

    	return;
    }
}



// main code begins now

int main()
{
	tree ans;
	int n,m,test,x,y;
    cin >> n >> m ;
    for (int i = 1; i <= n; ++i) {
    	scanf("%1d",&a[i]);
    }
    build(1,1,n);
    for (int i = 0; i < m; ++i) {
    	cin >> test >> x >> y ;
    	if(test==1) {
    		update(1,x,1,n,y);
    	}
    	else {
    		ans=query_min(1,1,n,x,y);
    		cout << ans.sum << endl ;
    	}
    }
    return 0;
}