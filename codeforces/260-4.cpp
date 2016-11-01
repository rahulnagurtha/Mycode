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

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                         100007


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
    TrieNode* children[2];
    // Initialize your data structure here.
    TrieNode() {
        prefixes = 0;
        for (int i = 0;i < 2;i++){
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
    		if(tmp->children[word[i]-'0'] == NULL) {
    			tmp->children[word[i]-'0'] = new TrieNode();
    		}
    		tmp = tmp->children[word[i]-'0'];
    	}
    	tmp->prefixes++;
    	return;
    }

    //remove one occurance of the word
    void removeWord(string word) {
    	TrieNode* current = root;
    	current->prefixes--;
    	for (int i = 0; i < word.size(); ++i) {
    		if(word[i] == '0') current = current->children[0];
    		else current = current->children[1];
    		current->prefixes--;
    	}
    	return;
    }

    //maximum Xor with the current string
    int maxXor(string word) {
    	int ans = 0;
    	TrieNode* tmp = root;
    	for (int i = 0; i < word.size(); ++i) {
    		ans = ans << 1;
    		if(word[i] == '0') {
    			if(tmp->children[1] != NULL && tmp->children[1]->prefixes > 0) {
    				ans++;
    				tmp = tmp->children[1];
    			}
    			else {
    				tmp = tmp->children[0];
    			}
    		}
    		else {
    			if(tmp->children[0] != NULL && tmp->children[0]->prefixes > 0) {
    				ans++;
    				tmp = tmp->children[0];
    			}
    			else {
    				tmp = tmp->children[1];
    			}
    		}
    	}
    	return ans;
    }
    void printTrie(TrieNode *cur) {
    	if(cur->children[0] == NULL && cur->children[1] == NULL) {
    		for (deque<char>::iterator it = Q.begin(); it != Q.end(); ++it)
		    	cout << ' ' << *it;
		    printf("\n");
		    return;
    	}
    	if(cur->children[0] != NULL) {
    		Q.push_back('0');
    		printTrie(cur->children[0]);
    		Q.pop_back();
    	}
    	if(cur->children[1] != NULL) {
    		Q.push_back('1');
    		printTrie(cur->children[1]);
    		Q.pop_back();
    	}
    }

};


inline void Refresh() {
    
}


int main()
{
    
    return 0;
}
