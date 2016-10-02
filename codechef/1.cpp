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
#define INF                     INT_MAX
#define N                       100007


typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};

int n;
int L,R;
int maxSoFar;
int value[105][2][2];
int ctr[10005];

int check(int curPos) {
	if(curPos > n) return n;
	int tmpAns = curPos - 1;
	bool isPossible;
	//live -> value[0]
	isPossible = true;
	for (int i = value[curPos][0][0]; i <= value[curPos][0][1]; ++i) {
		if(ctr[i] != 0) {
			isPossible = false;
			break;
		}
	}
	if(isPossible) {
		for (int i = value[curPos][0][0]; i <= value[curPos][0][1]; ++i) {
			ctr[i]++;
		}
		tmpAns = max(tmpAns,check(curPos + 1));
		if(tmpAns == n) return n;
		for (int i = value[curPos][0][0]; i <= value[curPos][0][1]; ++i) {
			ctr[i]--;
		}
	}
	//repeat -> value[1]
	isPossible = true;
	for (int i = value[curPos][1][0]; i <= value[curPos][1][1]; ++i) {
		if(ctr[i] != 0) {
			isPossible = false;
			break;
		}
	}
	if(isPossible) {
		for (int i = value[curPos][1][0]; i <= value[curPos][1][1]; ++i) {
			ctr[i]++;
		}
		tmpAns = max(tmpAns,check(curPos + 1));
		for (int i = value[curPos][1][0]; i <= value[curPos][1][1]; ++i) {
			ctr[i]--;
		}
	}
	// cout << curPos << " -- " << tmpAns << endl;
	return tmpAns;
}



int main()
{
    int q;
    si(q);
    while(q--) {
    	int slive,elive,srepeat,erepeat;
    	fill(ctr,0);
    	maxSoFar = 0;
    	L = R = -1;
    	si(n);
    	for (int i = 1; i <= n; ++i) {
    		si2(slive,elive);
    		si2(srepeat,erepeat);
    		value[i][0][0] = slive;
    		value[i][0][1] = elive;
    		value[i][1][0] = srepeat;
    		value[i][1][1] = erepeat;
    	}
    	int endPoint;
    	for (int i = 1; i <= n; ++i) {
    		endPoint = check(i);
    		// cout << i << "->" << endPoint << endl;
    		if(endPoint - i + 1 > maxSoFar) {
    			maxSoFar = endPoint - i + 1;
    			L = i;
    			R = endPoint;
    		}
    		if(maxSoFar == n - i + 1) break;
    	}
    	printf("%d %d\n",L,R);
    }
    return 0;
}