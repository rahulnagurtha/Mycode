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

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;


//true,largest,length

LL ldp[100005];
LL rdp[100005];
LL n,arr[100005],answer;


void solve() {
	ldp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if(arr[i] > arr[i-1]) ldp[i] = ldp[i-1]+1;
		else ldp[i] = 1;
	}
	rdp[n] = 1;
	for (int i = n-1; i >= 1; --i) {
		if(arr[i] < arr[i+1]) rdp[i] = rdp[i+1]+1;
		else rdp[i] = 1;
	}
	answer = 1;
	answer = max(answer,rdp[2]+1);
	for (int i = 1; i <= n-2; ++i) {
		if(arr[i] + 1 < arr[i+2]) answer = max(answer,ldp[i]+1+rdp[i+2]);
		answer = max(answer,1+rdp[i+1]);
		answer = max(answer,1+ldp[i-1]);
	}
	answer = max(answer,1+rdp[n-1]);
	answer = max(answer,1+rdp[n]);
	answer = max(answer,1+ldp[n-2]);
	answer = max(answer,ldp[n-1]+1);
	cout << answer ;
}


// main code begins now

int main()
{
	cin >> n ;
	for (int i = 1; i <= n; ++i) {
	    cin >> arr[i];
	}
	if(n==1) {
		printf("1\n");
		return 0;
	}
	if(n==2) {
		printf("2\n");
		return 0;
	}
	solve();
	return 0;
}