#include <bits/stdc++.h>

using namespace std;



#define si(i) 					scanf("%d",&i)
#define slli(i) 				scanf("%lld",&i)

#define pi(i) 					printf("%d\n",i)
#define plli(i) 				printf("%lld\n",i)

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

LL arr[100005],bsize[350],fans[100005],toadd[350];
LL n,m,w,h;

void brute() {
	LL temp;
	for (int i = 0; i < m; ++i) {
		slli(w); slli(h);
		temp = -1;
		for (int j = 1; j <= w; ++j) {
			if(arr[j] > temp) temp = arr[j];
		}
		fans[i] = temp;
		for (int j = 1; j <= w; ++j) {
			arr[j] = temp + h;
		}
	}
	for (int i = 0; i < m; ++i) plli(fans[i]);
}


void initialise() {

}



// main code begins now

int main()
{
    slli(n);
    for (int i = 1; i <= n; ++i) slli(arr[i]);
    if(n < 4) brute();
    slli(m);
	slli(w); slli(h);
	initialise();
	for (int i = 1; i < m; ++i) {
		slli(w); slli(h);
	}
	for (int i = 0; i < m; ++i) plli(fans[i]);
    return 0;
}