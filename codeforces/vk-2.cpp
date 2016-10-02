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


int n,tmp,answer;
int cnt[5];


void sumup() {
	answer += cnt[4];
	answer += min(cnt[1],cnt[3]);
	answer += cnt[2]/2;
	tmp = min(cnt[1],cnt[3]);
	cnt[1] -= tmp;
	cnt[2] = cnt[2]%2;
	cnt[3] -= tmp;
	return;
}


void decide() {
	if(cnt[1] == 0 && cnt[3] == 0) {
		answer += cnt[2];
	}
	else if(cnt[2] == 0 && cnt[3] == 0) {
		answer += ceil(cnt[1],4);
	}
	else if(cnt[1] == 0 && cnt[2] == 0) {
		answer += cnt[3];
	}
	else if(cnt[1] == 0 && cnt[3] == 0) {
		answer += cnt[2];
	}
	else if(cnt[1] == 0) {
		answer += cnt[2] + cnt[3];
	}
	else {
		if(cnt[1] == 1 || cnt[1] == 2) {
			answer += 1;
		}
		else {
			answer += 1;
			cnt[1] -= 2;
			answer += ceil(cnt[1],4);
		}
	}
}


// main code begins now

int main()
{
    cin >> n ;
    for (int i = 0; i < n; ++i) {
    	cin >> tmp;
    	cnt[tmp]++;
    }
    sumup();
    if(cnt[1] != 0 || cnt[3] != 0 || cnt[2] != 0) decide();
    printf("%d\n",answer);
    return 0;
}