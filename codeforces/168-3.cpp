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
typedef vector<VI> VOVI;


LL n,arr[100005],temp,k;
LL lft,ryt,middle,pairs,normal;
bool status[100005];

void bsearch(LL a) {
	lft = 1,ryt = n;
	while(lft < ryt) {
		middle = (lft+ryt)/2;
		if(arr[middle] == a) lft = ryt = middle;
		else if(arr[middle] < a) lft = middle+1;
		else ryt = middle-1;
	}
	if(lft<=ryt && arr[lft] == a) {
		status[lft] = true;
		pairs++;
	}
	else normal++;
	return;
}

// main code begins now

int main()
{
	cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
    	cin >> arr[i];
    }
    sort(arr,arr+n+1);
    for (int i = 1; i <= n; ++i) {
		if(status[i] == false) {
			bsearch(k*arr[i]);
		}
    }
    printf("%I64d\n",normal+pairs);
    return 0;
}