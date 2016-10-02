#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif

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
    int freq;
    int lcount;
    int rcount;
    int lval;
    int rval;
};

struct tree seg[500001];

int a[100001];

// Build with array [i,j]

void build(int node,int i,int j) {
    if(i>j) return;
    if(i==j) {                        
        seg[node].lval = seg[node].rval = a[i];
        seg[node].freq = 1;
        seg[node].lcount = 1;
        seg[node].rcount = 1;
        return;
    }
    build(node*2,i,(i+j)/2);
    build(node*2+1,1+(i+j)/2,j);

    //calculating lval and rval parameters
    seg[node].lval = a[i];
    seg[node].rval = a[j];
    
    //calculating freq and val parameters
    if(seg[node*2].freq > seg[1+node*2].freq) seg[node].freq = seg[node*2].freq;
    else seg[node].freq = seg[node*2+1].freq;
    if((seg[node*2].rval == seg[node*2+1].lval) && (seg[node*2].rcount + seg[node*2+1].lcount > seg[node].freq)) {
        seg[node].freq = seg[node*2].rcount + seg[node*2+1].lcount;
    }
    
    //calculating lcount and rcount
    seg[node].lcount = seg[node*2].lcount ;
    if(seg[node*2].lval == seg[node*2+1].lval) seg[node].lcount += seg[1+node*2].lcount;

    //calculating rcount
    seg[node].rcount = seg[node*2+1].rcount ;
    if(seg[node*2].rval == seg[node*2+1].rval) seg[node].rcount += seg[node*2].rcount;  
    return;
}

struct tree query(int node,int a,int b,int i,int j) {
    struct tree retnode;
    if(a > b || a > j || b < i) {
        retnode.freq = -1;
        return retnode;
    }
    if(a >= i && b <= j) {
        return seg[node];
    }
    struct tree q1,q2;
    q1 = query(node*2, a, (a+b)/2, i, j);
    q2 = query(1+node*2, 1+(a+b)/2, b, i, j);
    struct tree res;
    if(q1.freq == -1) return q2;
    else if(q2.freq == -1) return q1;
    else {
        retnode.lval = q1.lval;
        retnode.rval = q2.rval;
        //calculating freq and val parameters
        if(q1.freq > q2.freq) retnode.freq = q1.freq;
        else retnode.freq = q2.freq;
        if((q1.rval == q2.lval) && (q1.rcount + q2.lcount > retnode.freq)) {
            retnode.freq = q1.rcount + q2.lcount;
        }
        //calculating lcount and rcount
        retnode.lcount = q1.lcount ;
        if(q1.lval == q2.lval) retnode.lcount += q2.lcount;

        //calculating rcount
        retnode.rcount = q2.rcount ;
        if(q1.rval == q2.rval) retnode.rcount += q1.rcount;
        return retnode;
    }
}


int main()
{
    while(1) {
        int n,q,l,r;
        struct tree temp;
        si(n);
        if(n == 0) break;
        si(q);
        for (int i = 1; i <= n; ++i) si(a[i]);
        build(1,1,n);
        for (int i = 0; i < q; ++i) {
            si2(l,r);
            temp = query(1,1,n,l,r);
            printf("%d\n",temp.freq);
        }
    }
    return 0;
}
