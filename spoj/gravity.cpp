#include <bits/stdc++.h>

using namespace std;



#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;




int main()
{
	SYNC;
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	string tmp;
    	char graph[105][105];
    	bool visited[105][105] = {false};
    	PII start;
    	int n,m,O,X,Y;
    	cin >> O >> m >> n;
    	getchar();
    	char alp;
    	for (int i = 0; i < m; ++i) {
    		for (int j = 0; j < n; ++j) {
    			scanf("%c",&alp);
    			graph[i+1][j+1] = alp;
    			if(alp == 'T') {
    				start = mp(i+1,j+1);
    			}
    		}
    		getchar();
    	}
    	for (int i = 0; i <= n+1; ++i) {
    		graph[0][i] = '#';
    	}
    	for (int i = 0; i <= n+1; ++i) {
    		graph[m+1][i] = '#';
    	}
    	for (int i = 0; i <= m+1; ++i) {
    		graph[i][0] = '#';
    	}
    	for (int i = 0; i <= m+1; ++i) {
    		graph[i][n+1] = '#';
    	}
    	int dist = 0;
    	deque<pair<PII,int> > Q;
    	visited[start.FF][start.SS] = true;
    	Q.pb(mp(start,0));
    	bool found = false;
    	while(!Q.empty()) {
    		dist = (Q.front()).SS + 1;
    		start = (Q.front()).FF;
    		X = start.FF;
    		Y = start.SS;
    		Q.pop_front();
    		if((!visited[X-1][Y-1]) && (graph[X-1][Y-1] != '#')) {
    			if(graph[X-1][Y-1] == 'S') {
    				found = true;
    				break;
    			}
    			visited[X-1][Y-1] = true;
    			Q.pb(mp(mp(X-1,Y-1),dist));
    		}
    		if((!visited[X][Y-1]) && (graph[X][Y-1] != '#')) {
    			if(graph[X][Y-1] == 'S') {
    				found = true;
    				break;
    			}
    			visited[X][Y-1] = true;
    			Q.pb(mp(mp(X,Y-1),dist));
    		}
    		if((!visited[X+1][Y-1]) && (graph[X+1][Y-1] != '#')) {
    			if(graph[X+1][Y-1] == 'S') {
    				found = true;
    				break;
    			}
    			visited[X+1][Y-1] = true;
    			Q.pb(mp(mp(X+1,Y-1),dist));
    		}
    		if((!visited[X-1][Y]) && (graph[X-1][Y] != '#')) {
    			if(graph[X-1][Y] == 'S') {
    				found = true;
    				break;
    			}
    			visited[X-1][Y] = true;
    			Q.pb(mp(mp(X-1,Y),dist));
    		}
    		if((!visited[X+1][Y]) && (graph[X+1][Y] != '#')) {
    			if(graph[X+1][Y] == 'S') {
    				found = true;
    				break;
    			}
    			visited[X+1][Y] = true;
    			Q.pb(mp(mp(X+1,Y),dist));
    		}
    		if((!visited[X-1][Y+1]) && (graph[X-1][Y+1] != '#')) {
    			if(graph[X-1][Y+1] == 'S') {
    				found = true;
    				break;
    			}
    			visited[X-1][Y+1] = true;
    			Q.pb(mp(mp(X-1,Y+1),dist));
    		}
    		if((!visited[X][Y+1]) && (graph[X][Y+1] != '#')) {
    			if(graph[X][Y+1] == 'S') {
    				found = true;
    				break;
    			}
    			visited[X][Y+1] = true;
    			Q.pb(mp(mp(X,Y+1),dist));
    		}
    		if((!visited[X+1][Y+1]) && (graph[X+1][Y+1] != '#')) {
    			if(graph[X+1][Y+1] == 'S') {
    				found = true;
    				break;
    			}
    			visited[X+1][Y+1] = true;
    			Q.pb(mp(mp(X+1,Y+1),dist));
    		}
    		if(dist > O) break;
    	}
    	if((found) && (dist <= O)) cout << "Possible" << endl;
    	else cout << "Impossible" << endl;
    }
    return 0;
}
