#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			    ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			    (a-(box(a,b))*b)
#define ceil(a,b) 			    ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			    ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007
#define N 1005
#define M 100005

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;



int V,E,in,out,weight,one,two;
LL ans;
vector<pair<int,PII> > edges;
PII parent[N];


struct sort_pred {
    bool operator()(const std::pair<int,pair<int,int> > &left, const std::pair<int,pair<int,int> > &right) {
        return left.first < right.first;
    }
};


void makeset(int total) {
    for (int i = 1; i <= total; ++i) {
        parent[i].FF = i;
        parent[i].SS = 0;
    }
}

int findset(int number) {
    if(number == parent[number].FF) {
        return parent[number].FF;
    }
    else {
        parent[number].FF = findset(parent[number].FF);
        return parent[number].FF;
    }
}

void combine(int one,int two) {
    if(parent[one].SS > parent[two].SS) {
        parent[two].FF = parent[one].FF;
    }
    else if(parent[one].SS < parent[two].SS) {
        parent[one].FF = parent[two].FF;
    }
    else {
        parent[two].FF = parent[one].FF;
        parent[one].SS++;
    }
    return;
}

// main code begins now

int main()
{
    scanf("%d %d",&V,&E);
    for (int i = 0; i < E; ++i) {
    	scanf("%d %d %d",&out,&in,&weight);
    	edges.pb(mp(weight,mp(out,in)));
    }
    sort(edges.begin(),edges.end(),sort_pred());
    makeset(V+2);
    for (int i = 0; i < E; ++i) {
        one = findset(edges[i].SS.FF);
        two = findset(edges[i].SS.SS);
        if(one != two) {
            ans += (LL)edges[i].FF;
            combine(one,two);
        }
    }
    printf("%lld\n",ans);
    return 0;
}