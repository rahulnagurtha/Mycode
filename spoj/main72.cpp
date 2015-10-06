#include <bits/stdc++.h>

using namespace std;

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

deque<int> rightnow,rightnow1;
bool possible[100005];

// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int n,numbers[105],sum1=0;
    	LL tmp;
    	LL sum = 0;
    	fill(possible,false);
    	scanf("%d",&n);
    	for (int i = 0; i < n; ++i) {
    		scanf("%d",&numbers[i]);
    		sum1 += numbers[i];
    	}
    	rightnow.clear();
    	rightnow1.clear();
    	deque<int>::iterator it;
    	possible[numbers[0]] = true;
    	possible[0] = true;
    	rightnow.push_back(numbers[0]);
    	rightnow.push_back(0);
    	for (int i = 1; i < n; ++i) {
    		if(i%2 == 1) {
    			rightnow1.clear();
	    		for (it=rightnow.begin();it!=rightnow.end();it++) {
			    	tmp = (LL)(*it) + (LL)numbers[i];
					if(possible[tmp] == false) {
						possible[tmp] = true ;
						rightnow1.push_front(tmp);
					}
    			}
    			for (it=rightnow.begin();it!=rightnow.end();it++) {
					rightnow1.push_front(*it);
    			}
    		}
    		else {
    			rightnow.clear();
	    		for (it=rightnow1.begin();it!=rightnow1.end();it++) {
			    	tmp = (LL)(*it) + (LL)numbers[i];
					if(possible[tmp] == false) {
						possible[tmp] = true ;
						rightnow.push_front(tmp);
					}
    			}
    			for (it=rightnow1.begin();it!=rightnow1.end();it++) {
					rightnow.push_front(*it);
    			}
    		}
    	}
    	for (int i = 0; i <= sum1; ++i) {
    		if (possible[i] == true) {
    			sum += (LL)(i);
    		}
    	}
    	printf("%lld\n",sum);
    }
    return 0;
}