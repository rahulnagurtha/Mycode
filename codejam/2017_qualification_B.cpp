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

#define forup(i,a,b)            for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b)            for(int i = (a); (i) > (b); --(i))
#define rep(i,a)                for(int i = 0; (i) < (a); ++(i))

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                       100007


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



VI tmp;


inline void Refresh() {
    tmp.clear();
}

void preprocess(ll cur) {
	while(cur > 0) {
		tmp.pb(cur%10);
		cur /= 10;
	}
	reverse(tmp.begin(), tmp.end());
	return;
}

bool is_valid(VI &a,ll cur) {
	for (ll i = 1; i < a.size(); ++i) {
		if(a[i-1] > a[i]) return false;
	}
	return true;
}

ll getnum(VI &a, int idx) {
	ll res = 0;
	for(int i = idx; i < a.size(); i++) {
		res = res*10 + a[i];
	}
	return res;
}

void solve_large() {
	VI answer(tmp.size());
	for (int i = 0; i < tmp.size(); ++i) {
		//try to set rest to tmp[i]
		for (int j = i; j < answer.size(); ++j) {
			answer[j] = tmp[i];
		}
		if(getnum(answer, i) > getnum(tmp, i)) {
			answer[i] = tmp[i] - 1;
			for (int j = i + 1; j < answer.size(); ++j) {
				answer[j] = 9;
			}
			break;
		}

	}
	reverse(answer.begin(), answer.end());
	while((answer.size() > 0) && (answer.back() == 0)) answer.pop_back();
	reverse(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i];
	}
	cout << endl;
	assert(is_valid(answer,getnum(answer,0)));
	return;
}

int main()
{
    int t;
    int testcase = 1;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
        cout << "Case #" << testcase << ": ";
        ll n;
        cin >> n;
        preprocess(n);
        solve_large();
        testcase++;
    }
    return 0;
}