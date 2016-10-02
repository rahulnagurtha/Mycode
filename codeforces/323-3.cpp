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



int a[250005],cnt1,temp,one,two,cnt,n;
VI answer;
map<int,int> data;
VI largest;

int main()
{
	si(n);
	for (int i = 1; i <= n*n; ++i) {
		si(a[i]);
	}
	if(n == 1) {
		printf("%d\n",a[1]);
		return 0;
	}
	sort(a+1,a+n*n+1);
	for (int i = 1; i <= n*n;) {
		cnt1 = 0;
		temp = a[i];
		while(i <= n*n && temp == a[i]) {
			cnt1++;
			i++;
			largest.pb(temp);
		}
		data[temp] = cnt1;
	}
	largest.pop_back();
	largest.pop_back();
	cnt = 2;
	answer.pb(a[n*n]);
	answer.pb(a[n*n-1]);
	data[a[n*n]]--;
	data[a[n*n-1]]--;
	one = __gcd(a[n*n-1],a[n*n]);
	data[one]--;
	data[one]--;
	while(cnt < n) {
		one = largest.back();
		largest.pop_back();
		while(data[one] == 0) {
			one = largest.back();
			largest.pop_back();
		}
		data[one]--;
		for (int i = 0; i < answer.size(); ++i) {
			two = __gcd(answer[i],one);
			data[two]--;
			data[two]--;
		}
		answer.pb(one);
		cnt++;
	}
	for (int i = 0; i < answer.size(); ++i) {
		printf("%d ",answer[i]);
	}
	printf("\n");
    return 0;
}