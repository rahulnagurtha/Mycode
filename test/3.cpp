struct tree {
    ll lazy;
    ll sum;
};

tree part[500001];

void build(ll node,ll i,ll j) {
    if(i>j) return;
    if(i==j) {                   
        part[node].sum = 0;
        part[node].lazy = 0;
        return;
    }
    build(node*2,i,(i+j)/2);
    build(node*2+1,1+(i+j)/2,j);
    part[node].sum=part[node*2].sum+part[1+node*2].sum;
    part[node].lazy=0;
    return;
}

ll query_sum(ll node,ll a,ll b,ll i,ll j) {
    if(a > b || a > j || b < i) return 0;    //invalid segment
    
    if(part[node].lazy!= 0) { // This node needs to be updated
        part[node].sum +=(ll)(b-a+1)*(part[node].lazy); // Update it
        if(a != b) {
            part[node*2].lazy += part[node].lazy; // Mark child as lazy
            part[node*2+1].lazy += part[node].lazy; // Mark child as lazy
        }
        part[node].lazy = 0; // Reset it
    }
    if(a >= i && b <= j) return part[node].sum;    //Current segment is totally within range [i, j]
    ll q1,q2;
    q1=query_sum(node*2, a, (a+b)/2, i, j);    //query left child
    q2=query_sum(1+node*2, 1+(a+b)/2, b, i, j); //query right child
    ll res = q1+q2;    //return the final result based on left and right child
    return res;
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(ll node, ll a, ll b, ll i, ll j, ll value) {

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