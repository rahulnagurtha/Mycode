#include <bits/stdc++.h>

using namespace std;



#define si(i) 					scanf("%d",&i)
#define slli(i) 				scanf("%I64d",&i)

#define pi(i) 					printf("%d\n",i)
#define plli(i) 				printf("%I64d\n",i)

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


LL n,d,tmp,pos,answer;
vector<LL> points;
vector<LL>::iterator low;

void solve() {
	answer = 0;
	tmp = points.size();
	for (LL i = 0; i < points.size()-2; ++i) {
		low = lower_bound(points.begin()+i+1,points.end(),points[i] + d);	
		if(low == points.end()) {
			answer += ((tmp-1-i)*(tmp-2-i))/2;
		}
		else {
			pos = low - points.begin();
			if(points[pos] > points[i]+d) pos--;
			if(pos - i >= 2) {
				answer += ((pos - i)*(pos - i - 1))/2;
			}
		}
	}
	printf("%I64d\n",answer);
}


// main code begins now

int main()
{
	slli(n);slli(d);
	for (int i = 0; i < n; ++i) {
		slli(tmp);
		points.pb(tmp);
	}
	if (n < 3) printf("0\n");
	else solve();
    return 0;
}