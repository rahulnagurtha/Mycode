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




#define CHILDREN             26


class TrieNode {
public:
    int prefixes;
    TrieNode* children[CHILDREN];
    // Initialize your data structure here.
    TrieNode() {
        prefixes = 0;
        for (int i = 0; i < CHILDREN; i++){
            children[i] = NULL;
        }
    }
};


class Trie {
public:
    TrieNode* root;
    deque<char> Q;
    Trie() {
        root = new TrieNode();
        root->prefixes = 1;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* tmp = root;
        for (int i = 0; i < word.size(); ++i) {
            tmp->prefixes++;
            if(tmp->children[word[i]-'a'] == NULL) {
                tmp->children[word[i]-'a'] = new TrieNode();
            }
            tmp = tmp->children[word[i]-'a'];
        }
        tmp->prefixes++;
        return;
    }
    string get_appropriate_filter(string word) {
    	string ans;
    	bool filtr_found = false;
    	TrieNode* tmp = root;
        for (int i = 0; i < word.size(); ++i) {
            ans += word[i];
            if(tmp->children[word[i]-'a'] == NULL) {
                filtr_found = true;
                break;
            }
            tmp = tmp->children[word[i]-'a'];
        }
        if(!filtr_found) ans = "SHIT";
    	return ans;
    } 

};

int n;
VS B,UB;
bool is_valid;
Trie unblocked;
string parity,src;
set<string> filters_so_far;

void form_unblocked_trie() {
	for (int i = 0; i < UB.size(); ++i) {
    	unblocked.insert(UB[i]);
    }
	return;
}

void form_the_filters() {
	is_valid = true;
	for (int i = 0; i < B.size(); ++i) {
		string tmp = unblocked.get_appropriate_filter(B[i]);
		if(tmp == "SHIT") {
			is_valid = false;
			return;
		}
		filters_so_far.insert(tmp);
	}
	return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> parity >> src;
    	if(parity == "-") B.pb(src);
    	else UB.pb(src);
    }
    form_unblocked_trie();
    form_the_filters();
    if(!is_valid) {
    	cout << "-1" << endl;
    	return 0;
    }
    cout << filters_so_far.size() << endl;
    for (auto it = filters_so_far.begin(); it != filters_so_far.end(); ++it) {
    	cout << *it << endl;
    }
    return 0;
}