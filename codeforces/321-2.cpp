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


LL n,d,money,factor,answer,temp;
VOLL friends;
VL data,sum;
VL::iterator low;

// main code begins now

int main()
{
    slli2(n,d);
    answer = -100;
    for (int i = 0; i < n; ++i) {
    	slli2(money,factor);
    	friends.pb(mp(money,factor));
    }
    sort(friends.begin(),friends.end());
    data.pb(friends[0].FF);
    sum.pb(friends[0].SS);
    factor = friends[0].SS;
    for (int i = 1; i < n; ++i) {
    	factor += friends[i].SS;
    	data.pb(friends[i].FF);
    	sum.pb(factor);
    }
    // cout << data << endl ;
    // cout << sum << endl;
    for (int i = n-1; i >= 0; --i) {
		low = lower_bound(data.begin(), data.end(),data[i]-d+1);
		if(low - data.begin() == 0) temp = sum[i];
		else temp = sum[i] - sum[(low - data.begin()) - 1];
		answer = max(answer,temp);
    }
    plli(answer);
    return 0;
}