#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif

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
#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                (((a)<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

ll a,b,c,d;
ll w,x,y,z;
ll a2,a3,b2,b3,c2,c3,d2,d3,ans;

int main()
{
	cin >> a >> b >> c >> d;
	while(a % 2 == 0) {
		a /= 2;
		a2++;
	}
	while(a % 3 == 0) {
		a /= 3;
		a3++;
	}
	while(b % 2 == 0) {
		b /= 2;
		b2++;
	}
	while(b % 3 == 0) {
		b /= 3;
		b3++;
	}
	while(c % 2 == 0) {
		c /= 2;
		c2++;
	}
	while(c % 3 == 0) {
		c /= 3;
		c3++;
	}
	while(d % 2 == 0) {
		d /= 2;
		d2++;
	}
	while(d % 3 == 0) {
		d /= 3;
		d3++;
	}
	if(a*b != c*d) {
		printf("-1\n");
		return 0;
	}
	if(a3 + b3 > c3 + d3) {
		ans += (a3 + b3 - c3 - d3);
		if(b3 >= a3 + b3 - c3 - d3) {
			b2 = b2 + (a3 + b3 - c3 - d3);
			b3 = b3 - (a3 + b3 - c3 - d3);
		}
		else {
			b2 = b2 + b3;
			a2 = a2 + a3 - c3 - d3;
			a3 = a3 - (a3 - c3 - d3);
			b3 = 0;
		}
	}
	else if(a3 + b3 < c3 + d3) {
		ans += (c3 + d3 - a3 - b3);
		if(d3 >= c3 + d3 - a3 - b3) {
			d2 = d2 + (c3 + d3 - a3 - b3);
			d3 = d3 - (c3 + d3 - a3 - b3);
		}
		else {
			d2 = d2 + d3;
			c2 = c2 + c3 - a3 - b3;
			c3 = c3 - (c3 - a3 - b3);
			d3 = 0;
		}
	}
	if(a2 + b2 > c2 + d2) {
		ans += (a2 + b2 - c2 - d2);
		if(a2 >= (a2 + b2 - c2 - d2)) {
			a2 = a2 - (a2 + b2 - c2 - d2);
		}
		else {
			b2 = b2 - (b2 - c2 - d2);
			a2 = 0;
		}
	}
	else if(a2 + b2 < c2 + d2) {
		ans += (c2 + d2 - a2 - b2);
		if(c2 >= (c2 + d2 - a2 - b2)) {
			c2 = c2 - (c2 + d2 - a2 - b2);
		}
		else {
			d2 = d2 - (d2 - a2 - b2);
			c2 = 0;
		}
	}
	while(a2 > 0) {
		a *= 2;
		a2--;
	}
	while(a3 > 0) {
		a *= 3;
		a3--;
	}
	while(b2 > 0) {
		b *= 2;
		b2--;
	}
	while(b3 > 0) {
		b *= 3;
		b3--;
	}
	while(c2 > 0) {
		c *= 2;
		c2--;
	}
	while(c3 > 0) {
		c *= 3;
		c3--;
	}
	while(d2 > 0) {
		d *= 2;
		d2--;
	}
	while(d3 > 0) {
		d *= 3;
		d3--;
	}
	cout << ans << endl;
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
    return 0;
}