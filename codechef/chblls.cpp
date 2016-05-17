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
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)
 
#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)
 
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
 
 
 
 
int main()
{
	int tmp;
	//1,2
	cout << "1" << endl;
	cout << "1 1" << endl;
	cout << "1 5" << endl;
	cin >> tmp;
	if(tmp == 1) {
		cout << "2" << endl;
		cout << "1" << endl;
		return 0;
	}
	if(tmp == -1) {
		cout << "2" << endl;
		cout << "5" << endl;
		return 0;
	}
	//3,4
	cout << "1" << endl;
	cout << "1 3" << endl;
	cout << "1 4" << endl;
	cin >> tmp;
	if(tmp == 1) {
		cout << "2" << endl;
		cout << "3" << endl;
		return 0;
	}
	if(tmp == -1) {
		cout << "2" << endl;
		cout << "4" << endl;
		return 0;
	}
	cout << "2" << endl;
	cout << "2" << endl;
    return 0;
}