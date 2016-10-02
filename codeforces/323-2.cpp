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


int a[1002],cnt,temp,changes,pos,n;
bool visited[1002],forward;


int main()
{
	fill(visited,false);
	cnt = 0;
	changes = 0;
    si(n);
    for (int i = 1; i <= n; ++i) {
    	si(a[i]);
    }
    pos = 1;
    forward = true;
    while(cnt < n) {
    	if(a[pos] <= cnt && visited[pos] == false) {
    		visited[pos] = true;
    		cnt++;
    	}
    	if(forward) pos++;
    	else pos--;
    	if(pos == 0) {
    		pos = 1;
    		forward = true;
    		if(cnt < n) changes++;
    	}
    	else if(pos == n+1) {
    		pos = n;
    		forward = false;
    		if(cnt < n) changes++;
    	}
    }
    pi(changes);
    return 0;
}