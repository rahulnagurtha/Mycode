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


inline void Refresh() {
    
}


int main()
{
    int n;
    string A;
    cin >> n;
    cin >> A;
    if(n == 12) {
    	string a;
    	int cnt = 10;
    	for (int i = 0; i < 10; ++i) {
    		for (int j = 0; j < 10; ++j) {
    			for (int k = 0; k < 10; ++k) {
    				for (int l = 0; l < 10; ++l) {
    					int lft = 10*i + j;
    					int ryt = 10*k + l;
    					int tmp = 0;
    					if((1 <= lft && lft <= 12) && (0 <= ryt && ryt <= 59)) {
    						if((A[0] - '0') != i) tmp++;
    						if((A[1] - '0') != j) tmp++;
    						if((A[3] - '0') != k) tmp++;
    						if((A[4] - '0') != l) tmp++;
    						if(tmp < cnt) {
    							cnt = tmp;
    							a = "";
    							a += (char)(i + '0');
    							a += (char)(j + '0');
    							a += ':';
    							a += (char)(k + '0');
    							a += (char)(l + '0');
    						}
    					}
    				}
    			}
    		}	
    	}
    	A = a;
    }
    else {
    	string a;
    	int cnt = 10;
    	for (int i = 0; i < 10; ++i) {
    		for (int j = 0; j < 10; ++j) {
    			for (int k = 0; k < 10; ++k) {
    				for (int l = 0; l < 10; ++l) {
    					int lft = 10*i + j;
    					int ryt = 10*k + l;
    					int tmp = 0;
    					if((0 <= lft && lft <= 23) && (0 <= ryt && ryt <= 59)) {
    						if((A[0] - '0') != i) tmp++;
    						if((A[1] - '0') != j) tmp++;
    						if((A[3] - '0') != k) tmp++;
    						if((A[4] - '0') != l) tmp++;
    						if(tmp < cnt) {
    							cnt = tmp;
    							a = "";
    							a += (char)(i + '0');
    							a += (char)(j + '0');
    							a += ':';
    							a += (char)(k + '0');
    							a += (char)(l + '0');
    						}
    					}
    				}
    			}
    		}	
    	}
    	A = a;
    }
    cout << A << endl;
    return 0;
}