#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

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

ll psum[100005],a,b,n;


int main()
{
    ll t,cnt = 1;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    slli(t);
    while(t--) {
    	ll lbound,ubound,one,two;
    	double ans = 0,toremove = 0;
    	psum[0] = 0;
    	slli3(n,a,b);
    	for(int i = 1; i <= n; ++i) {
    		slli(psum[i]);
    		psum[i] = psum[i-1] + psum[i];
    	}
    	// printf("Case #%lld: ",cnt);
    	cnt++;
    	if(a == b) {
			for(int i = 0; i < n; ++i) {
				if(a%psum[n] == psum[i]) {
					ans = 0;
					break;
				}
				if( a%psum[n] < psum[i+1]) {
					ans = psum[i+1]-psum[i];
					break;
				}
			}
    		printf("%.9lf\n",ans);
    		continue;
    	}
    	toremove = 0;
    	for(int i = 0; i < n; ++i) {
    		if(psum[i] >= b) break;
    		lbound = a/psum[n];
    		ubound = b/psum[n];
    		while(lbound*psum[n] + psum[i+1] < a) lbound++;
    		while(lbound*psum[n] + psum[i] > a) lbound--;
    		while(ubound*psum[n] + psum[i] > b) ubound--;
    		while(ubound*psum[n] + psum[i+1] < b) ubound++;
    		cout << lbound << "-----" << ubound << endl;

    		if(lbound*psum[n] + psum[i+1] <= a) lbound++;
    		if((lbound*psum[n] + psum[i] < a) && (lbound*psum[n]+psum[i+1] > a)) {
				if(lbound*psum[n]+psum[i+1] <= b) one = psum[i+1];
				else one = psum[i+1] - (lbound*psum[n]+psum[i+1] - b);
				two = psum[i] + (a - lbound*psum[n]);
				assert(one >= two);
				cout << one << "^2 - " << two << "^2" << endl;
				toremove = toremove + (double)(one*one-two*two)/2;
				lbound++;
    		}
    		if(ubound*psum[n] + psum[i] >= b) ubound--;
    		if((ubound*psum[n] + psum[i+1] > b) && (ubound*psum[n] + psum[i] < b) && (ubound*psum[n] + psum[i] > a)) {
    			one = psum[i+1] - (b - ubound*psum[n]);
    			if(ubound*psum[n]+psum[i] >= a) two = psum[i];
    			else two = psum[i] + (a - ubound*psum[n]);
    			assert(one >= two);
    			cout << one << "^2 - " << two << "^2" << endl;
    			// toremove = toremove + (double)((b+max(ubound*psum[n]+psum[i],a))*(b-max(ubound*psum[n]+psum[i],a)))/2;
    			toremove = toremove + (double)(one*one-two*two)/2;
    			ubound--;
    		}
    		// cout << toremove << endl;
    		// printf("%lld %lld\n",lbound,ubound);
    		if((lbound*psum[n]+psum[i+1] <= b) && (ubound*psum[n]+psum[i] >= a) && (ubound>=lbound)) {
    			cout << lbound << "-----" << ubound << endl;
    			toremove = toremove + (double)(((ubound-lbound+1)*(psum[i+1]+psum[i]))*(psum[i+1]-psum[i]))/2;
    		}
    	}

    	ans = (double)toremove/(b-a);
    	printf("%.9lf\n",ans);
    }
    fclose(stdout);
    return 0;
}
