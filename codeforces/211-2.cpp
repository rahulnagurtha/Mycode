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


LL n,k;
LL arr[10000005];
LL sum[10000005];
pair<LL,LL> indices;

void preprocess() {
	for (int i = 1; i <= n; ++i) sum[i] = sum[i-1] + arr[i];
	indices.FF = 1;
	indices.SS = k;
}


void solve() {
	for (int i = 1; i <= n-k+1; ++i) {
		if(sum[i+k-1]-sum[i-1] < sum[indices.SS]-sum[indices.FF-1]) {
			indices.FF = i;
			indices.SS = i+k-1;
		}
	}
	cout << indices.FF << endl;
	return;
}

// main code begins now

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
    	cin >> arr[i];
    }
    preprocess();
    solve();
    return 0;
}