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

#define MAXN 100010

int complete[MAXN];

int n,m;
string s;
VS A;

string compute(string source)
{
	string ans = source;
	int n = source.size();
	for (int i = 0; i < n; ++i) {
		if(source[i]>='A' && source[i]<='Z') ans[i] = source[i]-'A'+'a';
	}
	return ans;
}

struct Node
{
	ll period,complete,index;
	string message;
	void cal()
	{
		complete = 20;
		message = compute(message);
		if (1465948800LL <= period && period <= 1468540800LL) complete += 10;
		if(message.size() >= 100) complete += 10;
	}
}zzz[MAXN];


void takeInput() {
	si2(n,m);
	for (int i = 0; i < n; ++i) {
		cin >> s;
		A.pb(compute(s));
	}
	for (int i = 0; i < m; ++i) {
		cin >> zzz[i].index >> zzz[i].period;
		cin.ignore();
		getline(cin, zzz[i].message);
		zzz[i].cal();
	}
	return;
}

int main()
{
	takeInput();
	for (int i = 0; i < n; ++i) {
		fill(complete,0);
		int index = -1 , ans = 0;
		for (int j = 0; j < m; ++j) {
			complete[zzz[j].index] += ( (zzz[j].message.find(A[i],0) != string::npos) ? zzz[j].complete : 0);

		}
		for (int j = 0; j < 1001; ++j) {
			if(ans < complete[j]) {
				ans = complete[j];
				index = j;
			}
		}
		pi(index);
	}
	return 0;
}