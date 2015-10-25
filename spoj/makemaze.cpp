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


int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    si(t);
    while(t--) {
    	VOII holes;
    	PII entpoint,expoint,temp;
    	deque<PII> Q;
    	bool visited[21][21];
    	char cell[21][21];
    	int m,n,cnt = 0;
    	fill(visited,false);
    	si2(m,n);
    	getchar();
    	for (int i = 1; i <= m; ++i) {
    		for (int j = 1; j <= n; ++j) {
    			cell[i][j] = getchar();
    		}
    		getchar();
    	}

    	//checking top
    	for (int i = 1; i <= n; ++i) {
    		if(!visited[1][i] && cell[1][i] == '.') {
    			cnt++;
    			holes.pb(mp(1,i));
    			visited[1][i] = true;
    		}
    	}
    	//checking bottom
    	for (int i = 1; i <= n; ++i) {
    		if(!visited[m][i] && cell[m][i] == '.') {
    			cnt++;
    			holes.pb(mp(m,i));
    			visited[m][i] = true;
    		}
    	}
    	//checking left
    	for (int i = 1; i <= m; ++i) {
    		if(!visited[i][1] && cell[i][1] == '.') {
    			cnt++;
    			holes.pb(mp(i,1));
    			visited[i][1] = true;
    		}
    	}
    	//checking right
    	for (int i = 1; i <= m; ++i) {
    		if(!visited[i][n] && cell[i][n] == '.') {
    			cnt++;
    			holes.pb(mp(i,n));
    			visited[i][n] = true;
    		}
    	}
    	if(cnt != 2) {
    		printf("invalid\n");
    		continue;
    	}
    	fill(visited,false);
    	entpoint = holes[0];
    	expoint = holes[1];
    	Q.pb(entpoint);
    	visited[entpoint.FF][entpoint.SS] = true;
    	while(!Q.empty()) {
    		temp = Q.front();
    		// if(temp == expoint) break;
    		Q.pop_front();
    		if(temp.FF + 1 <= m && !visited[temp.FF + 1][temp.SS] && cell[temp.FF + 1][temp.SS] != '#') {
    			visited[temp.FF + 1][temp.SS] = true;
    			Q.pb(mp(temp.FF + 1,temp.SS));
    		}
    		if(temp.FF - 1 >= 1 && !visited[temp.FF - 1][temp.SS] && cell[temp.FF - 1][temp.SS] != '#') {
    			visited[temp.FF - 1][temp.SS] = true;
    			Q.pb(mp(temp.FF - 1,temp.SS));
    		}
    		if(temp.SS + 1 <= n && !visited[temp.FF][temp.SS + 1] && cell[temp.FF][temp.SS + 1] != '#') {
    			visited[temp.FF][temp.SS + 1] = true;
    			Q.pb(mp(temp.FF,temp.SS + 1));
    		}
    		if(temp.SS - 1 >= 1 && !visited[temp.FF][temp.SS - 1] && cell[temp.FF][temp.SS - 1] != '#') {
    			visited[temp.FF][temp.SS - 1] = true;
    			Q.pb(mp(temp.FF,temp.SS - 1));
    		}
    	}
    	if(!visited[expoint.FF][expoint.SS]) printf("invalid\n");
    	else printf("valid\n");
    }
    return 0;
}