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
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


int parent[200005],Rank[200005];
int original[200005],weight[200005];
int p1,p2,n,q,u,v;
PII temp;

priority_queue<PII,VOII,greater<PII> > data;

void init() {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		Rank[i] = 0;
		original[i] = weight[i];
		data.push(mp(weight[i],i));
	}
	return;
}


int fin(int temp1) {
	if(temp1 != parent[temp1]) {
		parent[temp1] = fin(parent[temp1]);
	}
	return parent[temp1];
}

void Union(int one,int two) {
	p1 = fin(one);
	p2 = fin(two);
	if( p1 != p2 ) {
		if(Rank[p1] > Rank[p2]) {
			parent[p2] = p1;
			original[p1] = original[p1] + original[p2];
			data.push(mp(original[p1],p1));
		}
		else {
			if(Rank[p1] == Rank[p2]) Rank[p2]++;
			parent[p1] = p2;
			original[p2] = original[p1] + original[p2];
			data.push(mp(original[p2],p2));
		}
	}
	return;
}


void query() {
	Union(u,v);
	while(1) {
		temp = data.top();
		// cout << temp.FF << "," << temp.SS << endl;
		if(original[fin(temp.SS)] != temp.FF) {
			data.pop();
			continue;
		}
		printf("%d\n",temp.FF);
		break;
	}
}

// main code begins now


int main()
{
    si2(n,q);
    for (int i = 1; i <= n; ++i) si(weight[i]);
    init();
	for (int i = 0; i < q; ++i) {
		si2(u,v);
		query();
	}
    return 0;
}