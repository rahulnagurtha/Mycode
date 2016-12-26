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

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

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



ll k,n;
ll ans;
vector<pair<string,ll> > A;
vector<pair<string,ll> > normal,palindromes;
map<string,deque<ll> > auxPalin,auxNonPalin;
vector<VL> pendingDescisions;
ll max_beauty_of_ind_palindrome;

bool inline isPalindrome(string &src) {
	ll lft = 0;
	ll ryt = src.size() - 1;
	while(lft < ryt) {
		if(src[lft] != src[ryt]) return false;
		lft++;
		ryt--;
	}
	return true;
}


bool cmp(pair<string,ll> lft,pair<string,ll> ryt) {
	if(lft.FF == ryt.FF) return lft.SS > ryt.SS;
	else return lft.FF < ryt.FF;
}


void processNormal() {
	for (ll i = 0; i < normal.size(); ++i) {
		string tmp = normal[i].FF;
		reverse(tmp.begin(), tmp.end());
		auto it = auxNonPalin.find(tmp);
		if(it != auxNonPalin.end()) {
			if((it->SS).front() + normal[i].SS > 0) {
				ans += (it->SS).front() + normal[i].SS;
				(it->SS).pop_front();
				if((it->SS).size() == 0) auxNonPalin.erase(it->FF);
			}
			else auxNonPalin.erase(it->FF);
		}
		else {
			auxNonPalin[normal[i].FF].pb(normal[i].SS);
		}
	}
	return;
}


void processPlaindromes() {
	for (ll i = 0; i < palindromes.size(); ++i) {
		auxPalin[palindromes[i].FF].pb(palindromes[i].SS);
	}
	max_beauty_of_ind_palindrome = INT_MIN;
	for (auto it = auxPalin.begin(); it != auxPalin.end() ; ++it) {
		deque<ll> pos = it->SS;
		deque<ll> neg;
		while(pos.size() > 0) {
			if(pos.back() <= 0) {
				neg.push_front(pos.back());
				pos.pop_back();
			}
			else break;
		}
		VL cur;
		if(pos.size() % 2 == 1) {
			cur.pb(pos.back());
			pos.pop_back();
		}
		while(pos.size() > 0) {
			ans += pos.front();
			pos.pop_front();
		}
		if(cur.size() > 0 && neg.size() > 0) {
			cur.pb(neg.front());
		}
		if(cur.size() == 2) pendingDescisions.pb(cur);
		if(cur.size() == 1) {
			max_beauty_of_ind_palindrome = max(cur[0],max_beauty_of_ind_palindrome);
		}
	}
	return;
}

void processPending() {
	ll shit = 0;
	ll total_score = 0;
	for (int i = 0; i < pendingDescisions.size(); ++i) {
		if(pendingDescisions[i][0] + pendingDescisions[i][1] > 0) {
			total_score += pendingDescisions[i][0] + pendingDescisions[i][1];
		}
	}
	shit = max(shit,total_score + max_beauty_of_ind_palindrome);
	for (int i = 0; i < pendingDescisions.size(); ++i) {
		//make him the odd man
		ll tmp = pendingDescisions[i][0];
		for (int j = 0; j < pendingDescisions.size(); ++j) {
			if(i == j) continue;
			if(pendingDescisions[j][0] + pendingDescisions[j][1] > 0) {
				tmp += pendingDescisions[j][0] + pendingDescisions[j][1];
			}
		}
		shit = max(tmp,shit);
	}
	if(shit > 0) ans += shit;
	return;
}

int main()
{
	SYNC;
	ll beauty;
	string tmp;
	cin >> k >> n;
	for (ll i = 0; i < k; ++i) {
		cin >> tmp >> beauty;
		if(isPalindrome(tmp)) palindromes.pb(mp(tmp,beauty));
		else normal.pb(mp(tmp,beauty));
	}
	sort(normal.begin(),normal.end(),cmp);
	sort(palindromes.begin(),palindromes.end(),cmp);
	processNormal();
	processPlaindromes();
	processPending();
	cout << ans << endl;	
    return 0;
}