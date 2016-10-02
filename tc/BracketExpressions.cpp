#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
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

class BracketExpressions
{
public:
	int cnt;
	vector<string> substitute;
	void addAndRemove(char src,string &B) {
		B += src;
		generate(B);
		B.pop_back();
	}
	void generate(string &B) {
		if(B.size() == cnt) {
			substitute.pb(B);
			return;
		}
		addAndRemove('(',B);
		addAndRemove(')',B);
		addAndRemove('[',B);
		addAndRemove(']',B);
		addAndRemove('{',B);
		addAndRemove('}',B);
		return;
	}
	void preprocess(string A) {
		cnt = 0;
		for (int i = 0; i < A.size(); ++i) {
			if(A[i] == 'X') cnt++;
		}
		if(cnt == 0) {
			substitute.pb("");
		}
		else {
			string tmp;
			generate(tmp);
		}
		return;
	}
	bool isOpening(char src) {
		return (src == '(' || src == '[' || src == '{');
	}
	bool isValidPair(char lft,char ryt) {
		return ( (lft == '(' && ryt == ')') || 
				 (lft == '[' && ryt == ']') || 
				 (lft == '{' && ryt == '}')
				);
	}
	bool isValid(string A) {
		stack<char> T;
		for (int i = 0; i < A.size(); ++i) {
			if(isOpening(A[i])) {
				T.push(A[i]);
			}
			else {
				if(T.size() == 0 || !isValidPair(T.top(),A[i])) return false;
				T.pop();
			}
		}
		return (T.size() == 0);
	}
	string change(int idx,string A) {
		int ptr = 0;
		for (int i = 0; i < A.size(); ++i) {
			if(A[i] == 'X') {
				A[i] = substitute[idx][ptr];
				ptr++;
			}
		}
		return A;
	}
	string ifPossible(string expression) {
		preprocess(expression);
		string tmp;
		if(substitute.size() == 1) {
			if(isValid(expression)) return "possible";
			else return "impossible";
		}
		else {
			for (int i = 0; i < substitute.size(); ++i) {
				tmp = change(i,expression);
				if(isValid(tmp)) return "possible";
			}
			return "impossible";
		}
	}
};