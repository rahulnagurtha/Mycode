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
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;



int main()
{
    int m,s,tmp;
    string Max,Min;
    cin >> m >> s;
    if(s <= 9 && m == 1) {
    	cout << s << " " << s << endl;
    }
    else if(s == 0 && m > 1) {
    	cout << "-1 -1" << endl;
    }
    else if(s > m*9) {
    	cout << "-1 -1" << endl;
    }
    else {
    	tmp = s;
    	for (int i = 0; i < m; ++i) {
    		Max += (char)(48 + min(tmp,9));
    		tmp = tmp - min(tmp,9);
    	}
    	for (int i = 1; i <= 9; ++i) {
    		if(s-i <= 9*(m-1)) {
    			tmp = s-i;
    			cout << (char)(48+i);
    			for (int j = 1; j < m; ++j) {
    				Min += (char)(48 + min(tmp,9));
    				tmp = tmp - min(tmp,9);
    			}
    			for (int j = Min.size()-1; j >= 0; --j) {
    				cout << Min[j];
    			}
    			cout << " " << Max << endl;
    			break;
    		}
    	}
    }
    return 0;
}
