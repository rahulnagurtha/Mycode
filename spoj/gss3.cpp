#include <bits/stdc++.h>

using namespace std;



typedef long long int LL;



struct tree {
	LL high;
	LL lhigh;
	LL rhigh;
	LL sum;
};

tree part[500001];

LL arr[100001];


void build(LL node,LL i,LL j) {

	if(i>j) return;		 // invalid range to build
	if(i==j) {				
		part[node].lhigh = arr[i];			// Leaf nodes initialisation
		part[node].rhigh = arr[i];
		part[node].high = arr[i];
		part[node].sum = arr[i];
		return;
	}

	build(node*2,i,(i+j)/2);	// Init left child
	build(node*2+1,1+(i+j)/2,j);	// Init right child

	//update the sum
	part[node].sum=part[node*2].sum+part[1+node*2].sum;
	//update lhigh
	part[node].lhigh = max(part[2*node].lhigh,part[2*node].sum + part[1+2*node].lhigh);
	//update rhigh
	part[node].rhigh = max(part[1+2*node].rhigh,part[1+2*node].sum + part[2*node].rhigh);
	//update high
	part[node].high = max(part[2*node].rhigh + part[1+2*node].lhigh,max(part[2*node].high,part[1+2*node].high));
	return;
}

struct tree query_sum(LL node,LL a,LL b,LL i,LL j) {
	struct tree dummy;
	if(a > b || a > j || b < i) {
		dummy.high = -99999999999;
		dummy.lhigh = -99999999999;
		dummy.rhigh = -99999999999;
		dummy.sum = -99999999999;
		return dummy;	//invalid segment
	}
	if(a >= i && b <= j) {
		dummy.high = part[node].high;
		dummy.lhigh = part[node].lhigh;
		dummy.rhigh = part[node].rhigh;
		dummy.sum = part[node].sum;
		return dummy;	//Current segment is totally within range [i, j]
	}
	struct tree q1,q2;

	q1=query_sum(node*2, a, (a+b)/2, i, j);	//query left child
	q2=query_sum(1+node*2, 1+(a+b)/2, b, i, j); //query right child
	
	struct tree res;
	if(q1.high != -99999999999 && q2.high != -99999999999) {
		res.high = max(q1.high,max(q2.high,q1.rhigh+q2.lhigh));
		res.lhigh = max(q1.lhigh,q1.sum+q2.lhigh);
		res.rhigh = max(q2.rhigh,q2.sum+q1.rhigh);
		res.sum = q1.sum + q2.sum;
	}
	else if(q1.high == -99999999999) {
		res = q2;
	}
	else res = q1;
	
	return res;
}


void update(LL node,LL pos,LL i,LL j,LL val) {
    if(i>j) return;	//invalid segment


    if(i==j&&i==pos) {			
        part[node].lhigh = val;
		part[node].rhigh = val;
		part[node].high = val;
		part[node].sum = val;
        return;
    }

    if(i<=pos&&j>=pos) {
        update(2*node,pos,i,(i+j)/2,val);	//update left child
        update(2*node+1,pos,(i+j)/2 + 1,j,val);	//update right child
        //update the sum
		part[node].sum=part[node*2].sum+part[1+node*2].sum;
		//update lhigh
		part[node].lhigh = max(part[2*node].lhigh,part[2*node].sum + part[1+2*node].lhigh);
		//update rhigh
		part[node].rhigh = max(part[1+2*node].rhigh,part[1+2*node].sum + part[2*node].rhigh);
		//update high
		part[node].high = max(part[2*node].rhigh + part[1+2*node].lhigh,max(part[2*node].high,part[1+2*node].high));
    	return;
    }
}

// main code begins now

int main()
{
    LL n,m,a,b,tmp,type;
    cin >> n ;
    for (LL i = 1; i <= n; ++i) {
    	cin >> arr[i] ;
    }
    build(1,1,n);
    cin >> m ;
    for (LL i = 0; i < m; ++i) {
    	cin >> type >> a >> b ;
    	if(type == 1) {
	    	tmp = query_sum(1,1,n,a,b).high;
    		cout << tmp << endl;
    	}
    	else {
    		update(1,a,1,n,b);
    	}
    }
    return 0;
}