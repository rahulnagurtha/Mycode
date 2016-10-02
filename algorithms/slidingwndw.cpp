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



// main code begins now

int main()
{
    VI points;
    deque<PII> window;
    int n,k,tmp;
    si(n);si(k);
    for (int i = 0; i < n; ++i) {
    	si(tmp);points.pb(tmp);
    }
    //initialise window
    for (int i = 0; i < k; ++i) {
    	window.pb(mp(points[i],i));
    }
    sort(window.begin(),window.end());
    printf("%d ",window.front().FF);
    for (int i = k; i < n; ++i) {
    	while( !window.empty() && window.back().FF >= points[i]) window.pop_back();
    	window.pb(mp(points[i],i));
    	while(window.front().SS < i+1-k) window.pop_front();
    	printf("%d ",window.front().FF);
    }
    printf("\n");
    return 0;
}