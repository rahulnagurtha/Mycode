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


string inp;
VOLL takeoff;
VOLL offset;
LL a,b;

PLL nextcell(PLL A,char dir) {
	if(dir == 'U') A.SS++;
	else if(dir == 'D') A.SS--;
	else if(dir == 'L') A.FF--;
	else A.FF++;
	return A;
}

void preprocess() {
	PLL present,temp;
	present.FF = 0;
	present.SS = 0;
	for (int i = 0; i < inp.size(); ++i) {
		takeoff.pb(present);
		present = nextcell(present,inp[i]);
	}
	offset.pb(present);
	for (int i = 1; i < inp.size(); ++i) {
		present = nextcell(present,inp[i-1]);
		offset.pb(mp(present.FF-takeoff[i].FF,present.SS-takeoff[i].SS));
	}
	return;
}


void solve() {
	bool X,Y;
	int stepX,stepY;
	for (int i = 0; i < takeoff.size(); ++i) {
		X = false;
		Y = false;
		if(a == takeoff[i].FF && b == takeoff[i].SS) {
			printf("Yes\n");
			return;
		}
		//X-coordinate
		if(offset[i].FF == 0) {
			if(takeoff[i].FF == a) {
				X = true;
				stepX = INT_MAX;
			}
		}
		else {
			if(abs(a-takeoff[i].FF)%abs(offset[i].FF) == 0) {
				stepX = (a-takeoff[i].FF)/offset[i].FF;
				X = true;	
			}
			else {
				X = false;
			}
		}
		//Y-coordinate
		if(offset[i].SS == 0) {
			if(takeoff[i].SS == b) {
				stepY = INT_MAX;
				Y = true;
			}
		}
		else {
			if(abs(b-takeoff[i].SS)%abs(offset[i].SS) == 0) {
				stepY = (b-takeoff[i].SS)/offset[i].SS;
				Y = true;	
			}
			else {
				Y = false;
			}
		}
		if(stepY == INT_MAX) stepY = stepX;
		if(stepX == INT_MAX) stepX = stepY;
		if(X && Y) {
			if(stepX == stepY && stepY >= 0) {
				printf("Yes\n");
				return;
			}
		}
	}
	printf("No\n");
	return;
}

// main code begins now

int main()
{
    cin >> a >> b ;
    cin >> inp;
    preprocess();
    solve();
    return 0;
}