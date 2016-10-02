#include <bits/stdc++.h>

using namespace std;


typedef long long int ll;



struct tree {
    ll lazy;
    ll sum;
};

tree part[500001];


/*
****the indexing can be from [0,n-1] or [1,n]
****based on the type pass the necessary arguments
****for example if [0,n-1] update(1,x,0,n-1,y) 
                if [1,n] update(1,x,1,n,y);
*/



// Build and init tree with array [i,j]

void build(int node,int i,int j) {

    if(i>j) return;         // invalid range to build
    if(i==j) {                        
        part[node].sum=0;
        part[node].lazy=0;
        return;
    }

    build(node*2,i,(i+j)/2);    // Init left child
    build(node*2+1,1+(i+j)/2,j);    // Init right child

    //update the node based on the values of left and right nodes
    part[node].sum=part[node*2].sum+part[1+node*2].sum;
    part[node].lazy=0;
    return;
}


/**
 * Query tree to get sum within range [i, j]
 */
ll query_sum(int node,int a,int b,int i,int j) {

    if(part[node].lazy!= 0) { // This node needs to be updated
        part[node].sum +=(ll)(b-a+1)*(part[node].lazy); // Update it
 
        if(a != b) {
            part[node*2].lazy += part[node].lazy; // Mark child as lazy
            part[node*2+1].lazy += part[node].lazy; // Mark child as lazy
        }
 
        part[node].lazy = 0; // Reset it
    }

    if(a > b || a > j || b < i) return 0;    //invalid segment


    if(a >= i && b <= j) return part[node].sum;    //Current segment is totally within range [i, j]

    ll q1,q2;

    q1=query_sum(node*2, a, (a+b)/2, i, j);    //query left child
    q2=query_sum(1+node*2, 1+(a+b)/2, b, i, j); //query right child
    
    // printf("adding %lld,%lld\n",q1,q2);
    ll res = q1+q2;    //return the final result based on left and right child
    
    return res;
}




/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

    if(part[node].lazy != 0) { // This node needs to be updated
        
        part[node].sum += (ll)(b-a+1)*(part[node].lazy); // Update it
        
        if(a != b) {
            part[node*2].lazy += part[node].lazy; // Mark child as lazy
            part[node*2+1].lazy += part[node].lazy; // Mark child as lazy
        }
        
        part[node].lazy = 0; // Reset it
    }

    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    
    if(a >= i && b <= j) { // Segment is fully within range
        part[node].sum += (ll)(b-a+1)*value;

        if(a != b) { // Not leaf node
            part[node*2].lazy += (ll)value;
            part[node*2+1].lazy += (ll)value;
        }
        return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
    part[node].sum = part[node*2].sum + part[1+node*2].sum; // Updating root with max value
    
}


// main code begins now


int main(){
    int TC,N,C;
    int op,p,q,v;
    // freopen("in.txt", "r", stdin);
    cin >> TC ;
    
    while(TC--){
        cin >> N >> C ;
        build(1,1,N);
        for(int i = 0;i < C;++i){
            cin >> op ;
            
            if(op == 0){
                cin >> p >> q >> v ;
                update_tree(1,1,N,p,q,v);
                // printstatus();
            }
            else{
                cin >> p >> q ;
                printf("%lld\n",query_sum(1,1,N,p,q));
                // printstatus();
            }
        }
    }
    
    return 0;
}
