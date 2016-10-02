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


class TrieNode {
public:
    int prefixes;
    bool isWord;
    TrieNode* children[10];
    // Initialize your data structure here.
    TrieNode() {
        prefixes = 0;
        isWord = false;
        for (int i = 0;i < 10;i++){
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
    bool insert(string word) {
    	TrieNode* tmp = root;
    	for (int i = 0; i < word.size(); ++i) {
    		tmp->prefixes++;
    		if(tmp->isWord) return false;
    		if(tmp->children[word[i]-'0'] == NULL) {
    			tmp->children[word[i]-'0'] = new TrieNode();
    		}
    		tmp = tmp->children[word[i]-'0'];
    	}
    	tmp->prefixes++;
    	tmp->isWord = true;
    	return (tmp->prefixes == 1);
    }
};


int main()
{
    int t;
    si(t);
    while(t--) {
    	Trie phoneBook;
    	int n;
    	string tmp;
    	si(n);
    	bool valid = true;
    	for (int i = 0; i < n; ++i) {
    		cin >> tmp;
    		if(valid) {
    			valid = phoneBook.insert(tmp);
    		}
    	}
    	if(valid) printf("YES\n");
    	else printf("NO\n");
    }
    return 0;
}
