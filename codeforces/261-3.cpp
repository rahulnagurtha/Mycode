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

int n,k,d;
int answer[1005][1005];
int current;

bool exist() {
	int temp = 1;
	for (int i = 0; i < d; ++i) {
		temp *= k;
		if(temp >= n) return true;
	}
	return false;
}

void init() {
	for (int i = 1; i <= d; ++i) answer[i][1] = 1;
	current = 2;
	return;
}

void modify() {
	for (int i = 1; i <= d; ++i) {
		if(answer[i][current-1] != k) {
			answer[i][current] = answer[i][current-1] + 1;
			i++;
			while(i <= d) {
				answer[i][current] = answer[i][current-1];
				i++;
			}
			current++;
			return;
		}
		answer[i][current] = 1;
	}
	current++;
	return;
}


// main code begins now

int main()
{
	cin >> n >> k >> d;
	if(!exist()) {
		printf("-1\n");
		return 0;
	}
	init();
	for (int i = 1; i <= n-1; ++i) modify();
	for (int i = 1; i <= d; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << answer[i][j] << " ";
		}
		printf("\n");
	}
    return 0;
}
