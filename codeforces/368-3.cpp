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

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

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

VL square;
ll number;

bool Hypotenuse(ll num) {
	ll m,n;
	m = n = -1;
	bool flag;
	for (int i = 0,j = square.size()-1; i < square.size(); ++i) {
		flag = false;
		for (;j > i;) {
			if(square[i] + square[j] == num) {
				m = square[j];
				n = square[i];
				flag = true;
				break;
			}
			if(square[i] + square[j] > num) j--;
			else break;
		}
		if(flag) break;
	}
	if(m != -1 && n != -1) {
		m = sqrt(m);
		n = sqrt(n);
		ll a,b,c,factor;
		a = m*m - n*n;
		b = 2*m*n;
		c = m*m + n*n;
		factor = number/c;
		cout << factor*a << " " << factor*b << endl;
		return true;
	}
	return false;
}


bool base(ll num) {
	ll m,n;
	m = n = -1;
	bool flag;
	for (int i = 0,j = 0; i < square.size(); ++i) {
		flag = false;
		for (j = max(i+1,j);j < square.size();) {
			if(square[j] - square[i] == num) {
				m = square[j];
				n = square[i];
				flag = true;
				break;
			}
			if(square[j] - square[i] < num) j++;
			else break;
		}
		if(flag) break;
	}
	if(m != -1 && n != -1) {
		m = sqrt(m);
		n = sqrt(n);
		ll a,b,c,factor;
		a = m*m - n*n;
		b = 2*m*n;
		c = m*m + n*n;
		factor = number/a;
		cout << factor*b << " " << factor*c << endl;
		return true;
	}
	return false;
}

int main()
{
	cin >> number;
    for (ll i = 1; i*i <= MOD; ++i) {
    	square.pb(i*i);
    }
    ll square_root = (ll)sqrt(number) + 1;
	for (ll i = 1; i < square_root; i++) { 
	    if (number % i == 0 && i*i != number) {
	       if(Hypotenuse(i) || Hypotenuse(number/i) || base(i) || base(number/i)) {
	       		return 0;	
	       }
	    }
	    if (number % i == 0 && i*i == number) {
	        if(Hypotenuse(i) || base(i)) {
	       		return 0;	
	       }
	    }
	}
	printf("-1\n");
    return 0;
}