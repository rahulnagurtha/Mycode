#include <bits/stdc++.h>

using namespace std;



#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


struct tree {
    int mi;
    int ma;
    int sum;
};

tree part[500001];

int arr[100002];

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
        part[node].mi=arr[i];            // Leaf nodes initialisation
        part[node].ma=arr[i];
        part[node].sum=arr[i];
        return;
    }

    build(node*2,i,(i+j)/2);    // Init left child
    build(node*2+1,1+(i+j)/2,j);    // Init right child

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

    if(a > b || a > j || b < i) return 2147483645;    //invalid segment
    if(a >= i && b <= j) return part[node].mi;        // Current segment is totally within range [i, j]
    
    int q1,q2;

    q1=query_min(node*2, a, (a+b)/2, i, j);    //query the left child
    q2=query_min(1+node*2, 1+(a+b)/2, b, i, j); //query the right child
    
    int res = min(q1, q2); //return the final result based on left and right child
    
    return res;
}




/**
 * Query tree to get max element value within range [i, j]
 */

int query_max(int node,int a,int b,int i,int j) {

    if(a > b || a > j || b < i) return -2147483645;    //invalid segment
    
    if(a >= i && b <= j) return part[node].ma;    // Current segment is totally within range [i, j]

    int q1,q2;

    q1=query_max(node*2, a, (a+b)/2, i, j);    //query the left child
    q2=query_max(1+node*2, 1+(a+b)/2, b, i, j);    //query the right child
    
    int res = max(q1, q2);    //return the final result based on left and right child
    
    return res;
}




/**
 * Query tree to get sum within range [i, j]
 */
int query_sum(int node,int a,int b,int i,int j) {
    if(a > b || a > j || b < i) return 0;    //invalid segment
    if(a >= i && b <= j) return part[node].sum;    //Current segment is totally within range [i, j]

    int q1,q2;

    q1=query_sum(node*2, a, (a+b)/2, i, j);    //query left child
    q2=query_sum(1+node*2, 1+(a+b)/2, b, i, j); //query right child
    
    int res = q1+q2;    //return the final result based on left and right child
    
    return res;
}


/**
 * update the pos indexed element in [i, j] with value val
 */

void update(int node,int pos,int i,int j,int val) {
    if(i>j) return;    //invalid segment

    if(i==j&&i==pos) {            
        part[node].ma=val;
        part[node].mi=val;        //update the leaf node
        part[node].sum=val;
        return;
    }

    if(i<=pos&&j>=pos) {
        update(2*node,pos,i,(i+j)/2,val);    //update left child
        update(2*node+1,pos,(i+j)/2 + 1,j,val);    //update right child
        part[node].ma=max(part[2*node].ma,part[2*node+1].ma);
        part[node].mi=min(part[2*node].mi,part[2*node+1].mi);    //update the nodes
        part[node].sum=part[2*node].sum+part[1+2*node].sum;
        return;
    }
}


/**
 * update the values in [i, j] with value val
 */

void update_range(int node,int a,int b,int i,int j,int val) {
    if(a > b || a > j || b < i) return;    //invalid segment
    if(a==b && a<=j && a>=i) {
        part[node].ma=val;
        part[node].mi=val;        //update the leaf node
        part[node].sum=val;
        return;
    }
    update_range(2*node,a,(a+b)/2,i,j,val);
    update_range(2*node+1,1+(a+b)/2,b,i,j,val);

    part[node].ma=max(part[2*node].ma,part[2*node+1].ma);
    part[node].mi=min(part[2*node].mi,part[2*node+1].mi);    //update the nodes
    part[node].sum=part[2*node].sum+part[1+2*node].sum;
    return;

}





int main()
{
    int t;
    int cnt = 0;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
        cnt++;
        int n,q,l,r;
        si2(n,q);
        for (int i = 1; i <= n; ++i) si(arr[i]);
        build(1,1,n);
        printf("Scenario #%d:\n",cnt);
        for (int i = 0; i < q; ++i) {
            si2(l,r);
            printf("%d\n",query_min(1,1,n,l,r));
        }
    }
    return 0;
}