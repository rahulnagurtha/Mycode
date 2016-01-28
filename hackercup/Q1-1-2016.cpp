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


int main()
{
    int t,cnt = 1;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    si(t);
    while(t--) {
    	int n,a[100005],last,sizeofQ,ans = 0;
    	si(n);
    	for(int i = 0; i < n; ++i) si(a[i]);
    	sizeofQ = 0;
	    last = -1;
    	for(int i = 0; i < n; ++i) {
			if(sizeofQ == 0) {
				last = a[i];
				sizeofQ = 1;
			}
			else if(sizeofQ == 1) {
				if(a[i] <= last) {
					ans += 3;
					last = a[i];
					sizeofQ = 1;
				}
				else if(a[i]-last > 10) {
					last += 10;
					i--;
					ans++;
					sizeofQ++;
				}
				else {
					sizeofQ++;
					last = a[i];
				}
			}
			else if(sizeofQ == 2) {
				if(a[i] <= last) {
					ans += 2;
					last = a[i];
					sizeofQ = 1;
				}
				else if(a[i]-last > 10) {
					last += 10;
					ans++;
					i--;
					sizeofQ++;
				}
				else {
					sizeofQ++;
					last = a[i];
				}
			}
			else if(sizeofQ == 3) {
				if(a[i] <= last) {
					ans += 1;
					last = a[i];
					sizeofQ = 1;
				}
				else if(a[i]-last > 10) {
					last += 10;
					ans++;
					i--;
					sizeofQ++;
				}
				else {
					sizeofQ++;
					last = a[i];
				}
			}
			else {
				last = a[i];
				sizeofQ = 1;
			}
    	}
    	if(sizeofQ == 1) ans += 3;
    	else if(sizeofQ == 2) ans += 2;
    	else if(sizeofQ == 3) ans += 1;
    	printf("Case #%d: %d\n",cnt,ans);
    	cnt++;
    }
    fclose(stdout);
    return 0;
}
