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

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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


VS parts;
string history;
VS commentsAtDepth[10*N];
VI T;


int convert_to_int(string src) {
	int val = 0;
	for (int i = 0; i < src.size(); ++i) {
		val = val*10 + (src[i] - '0');
	}
	return val;
}

bool check_if_its_digit(string src) {
	return ('0' <= src[0] && src[0] <= '9');
}



int main()
{
	SYNC;
	cin >> history;
	string tmp;
	for (int i = 0; i < history.size(); ++i) {
		if(history[i] == ',') {
			parts.pb(tmp);
			tmp = "";
		}
		else {
			tmp += history[i];
		}
	}
	for (int i = 0; i < parts.size(); ++i) {
		bool isDigit = check_if_its_digit(parts[i]);
		if(isDigit) {
			int val = convert_to_int(parts[i]);
			if(val != 0) T.pb(val);
		}
		else {
			while(T.size() > 0 && T.back() == 0) T.pop_back();
			int atDepth = T.size();
			commentsAtDepth[atDepth].pb(parts[i]);
			if(T.size() > 0) {
				T[T.size() - 1]--;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10*N; ++i) {
		if(commentsAtDepth[i].size() != 0) ans = i+1;
		else break;
	}
	cout << ans << endl;
	for (int i = 0; i < ans; ++i) {
		for (int j = 0; j < commentsAtDepth[i].size(); ++j) {
			cout << commentsAtDepth[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}