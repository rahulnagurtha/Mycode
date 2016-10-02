#include <bits/stdc++.h>

using namespace std;


typedef long long int ll;



struct tree {
    ll lazy,colour,sum;
};

tree part[500001];

void build(ll node,ll i,ll j) {

    if(i>j) return;
    if(i==j) {                        
        part[node].sum = 0;
        part[node].lazy = 0;
        part[node].colour = i;
        return;
    }

    build(node*2,i,(i+j)/2);
    build(node*2+1,1+(i+j)/2,j); 

    part[node].sum = part[node*2].sum + part[1+node*2].sum;
    part[node].lazy=0;
    return;
}


ll query_sum(ll node,ll a,ll b,ll i,ll j) {
    if(a > b || a > j || b < i) return 0;    
    
    if(part[node].colour != 0) {
        part[node].sum +=(ll)(b-a+1)*(part[node].lazy); 
 
        if(a != b) {
            part[node*2].lazy += part[node].lazy; 
            part[node*2+1].lazy += part[node].lazy; 
        }
 
        part[node].lazy = 0;
    }
    if(part[node].lazy != 0) {
        part[node].sum +=(ll)(b-a+1)*(part[node].lazy); 
 
        if(a != b) {
            part[node*2].lazy += part[node].lazy; 
            part[node*2+1].lazy += part[node].lazy; 
        }
 
        part[node].lazy = 0;
    }


    if(a >= i && b <= j) return part[node].sum; 

    ll q1,q2;

    q1=query_sum(node*2, a, (a+b)/2, i, j);
    q2=query_sum(1+node*2, 1+(a+b)/2, b, i, j); 
    
    ll res = q1+q2;    
    
    return res;
}




void update_tree(ll node, ll a, ll b, ll i, ll j, ll value) {

    if(part[node].lazy != 0) {
        part[node].sum += (ll)(b-a+1)*(part[node].lazy); 
        if(a != b) {
            part[node*2].lazy += part[node].lazy; 
            part[node*2+1].lazy += part[node].lazy; 
        }
        part[node].lazy = 0; 
    }

    if(a > b || a > j || b < i) 
        return;
    
    if(a >= i && b <= j) { 
        part[node].sum += (b-a+1)*abs(part[node].sum-value);
        part[node].colour = value;

        if(a != b) { 
            part[node*2].lazy += (ll)value;
            part[node*2+1].lazy += (ll)value;
        }
        return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value); 
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); 
    part[node].sum = part[node*2].sum + part[1+node*2].sum; 
    
}



// main code begins now

int main()
{
    int t;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {

    }
    return 0;
}