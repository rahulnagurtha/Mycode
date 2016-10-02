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
#define INF 					INT_MAX
#define N                     	100007


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

string addBinary(string A, string B) {
	// cout << A << " " << B << endl;
    string ans;
    int maxlen = max(A.size(),B.size());
    while(A.size() < maxlen) {
        A = '0' + A;
    }
    while(B.size() < maxlen) {
        B = '0' + B;
    }
    int carry = 0;
    int sum;
    for (int i = B.size() - 1; i >= 0; --i) {
        sum = 0;
        sum = carry + (A[i] - '0') + (B[i] - '0');
        if(sum == 10) {
        	ans = '0' + ans;
        	carry = 1;
        }
        else {
        	ans = (char)('0' + sum) + ans;
        	carry = 0;
        }
    }
    if(carry != 0) ans = '1' + ans;
    return ans;
}

int main()
{
	SYNC;
    int n,t;
    string ans;
    string s;
    cin >> n >> t;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
    	if(s[i] == '.') {
    		if(s[i+1] >= '5') {
    			// cout << s.substr(0,i) << endl;
    			cout << addBinary(s.substr(0,i),"1") << endl;
    			return 0;
    		}
    		ans = s.substr(0,i);
    		vector<char> T;
    		for (int j = i + 1; j < n; ++j) {
    			if(T.size() == 0) T.pb(s[j]);
    			else {
    				if(s[j] >= '5') {
    					char tmp = (T.back() + 1);
    					T.pop_back();
    					T.pb(tmp);
    					t--;
    					break;
    				}
    				else {
    					T.pb(s[j]);
    				}
    			}
    		}
    		// cout << T << endl;
    		while(true) {
    			if(t == 0) break;
    			if(T.size() == 1) break;
    			if(T.back() >= '5') {
    				T.pop_back();
    				T[T.size() - 1] = T[T.size() - 1] + 1;
    				t--;
    			}
    			else break;
    		}
    		if(T[0] >= '5' && t > 0) {
    			// cout << ans << endl;
    			cout << addBinary(ans,"1") << endl;
    			return 0;
    		}
    		string brandnew;
    		for (int k = 0; k < T.size(); ++k) {
    			brandnew += T[k];
    		}
    		cout << ans << "." << brandnew << endl;
    		return 0;
    	}
    }

    return 0;
}