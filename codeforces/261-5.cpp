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
#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                (((a)<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define INF                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


int n,m;

struct node {
    int u,v,w;
};

struct info {
    int max1,max2,wt2;
};

node edge[300005];
info vertex[300005];

bool cmp(node a,node b) {
    return a.w > b.w;
}


void update(int num,int nuval,int wt) {
    if (vertex[num].wt2 > wt) {
        vertex[num].max1 = max(vertex[num].max1,vertex[num].max2);
        vertex[num].max2 = nuval;
        vertex[num].wt2 = wt;
    }
    else {
        vertex[num].max2 = max(nuval,vertex[num].max2);
    }
}

int get(int num,int wt) {
    int ret = 0;
    ret = vertex[num].max1;
    if(vertex[num].wt2 > wt) {
        ret = max(ret,vertex[num].max2);
    }
    return ret;
}

int main()
{
    int ans = 0,tmp;
    si2(n,m);
    for (int i = 0; i < m; ++i) {
        si3(edge[i].u,edge[i].v,edge[i].w);
    }
    sort(edge,edge+m,cmp);
    for (int i = 1; i <= n; ++i) {
        vertex[i].max1 = vertex[i].max2 = 0;
        vertex[i].wt2 = INF; 
    }
    for (int i = 0; i < m; ++i) {
        tmp = get(edge[i].v,edge[i].w);
        update(edge[i].u,1+tmp,edge[i].w);
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans,max(vertex[i].max1,vertex[i].max2));
    }
    pi(ans);
    return 0;
}