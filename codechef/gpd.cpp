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


#define CHILDREN             2

string convert_and_pad(int src) {
	string tmp;
	while(src > 0) {
		if((src % 2) == 0) tmp = '0' + tmp;
		else tmp = '1' + tmp;
		src = src >> 1;
	}
	while(tmp.size() < 31) tmp = '0' + tmp;
	return tmp;
}


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
    void insert(int src) {
    	string word = convert_and_pad(src);
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

    // Inserts a word into the trie.
    void persistant_insert(TrieNode *lft,int src) {
    	string word = convert_and_pad(src);
        TrieNode *ryt = root;
        for (int i = 0; i < word.size(); ++i) {
        	ryt->children[word[i]-'0'] = new TrieNode();
        	if(lft != NULL) {
	        	ryt->children[((word[i]-'0') + 1) % 2] = lft->children[((word[i]-'0') + 1) % 2];  
	            lft = lft->children[word[i]-'0'];
        	}
        	ryt = ryt->children[word[i]-'0'];
        }
        return;
    }

    //get min xor with k
    int get_min_xor(int k) {
    	int ans = 0;
    	TrieNode* tmp = root;
    	string word = convert_and_pad(k);
        for (int i = 0; i < word.size(); ++i) {
        	ans = ans << 1;
            if(tmp->children[word[i]-'0'] != NULL) {
                tmp = tmp->children[word[i]-'0'];
            }
            else {
            	ans++;
            	tmp = tmp->children[((word[i]-'0') + 1) % 2];
            }
        }
        return ans;
    }

    //get max xor with k
    int get_max_xor(int k) {
    	int ans = 0;
    	TrieNode* tmp = root;
    	string word = convert_and_pad(k);
        for (int i = 0; i < word.size(); ++i) {
        	ans = ans << 1;
            if(tmp->children[((word[i]-'0') + 1) % 2] != NULL) {
            	ans++;
                tmp = tmp->children[((word[i]-'0') + 1) % 2];
            }
            else {
            	tmp = tmp->children[word[i]-'0'];
            }
        }
        return ans;
    }
};

map<int,Trie*> info;
int N,Q;
int R,key;


void intiate() {
	Trie *cur = new Trie();
	cur->insert(key);
	info[R] = cur;
	return;
}

void construct_persistant_trie(int u,int v,int k) {
	Trie *cur = new Trie();
	cur->persistant_insert(info[v]->root,k);
	info[u] = cur;
	return;
}

int main()
{
	SYNC;
    // freopen("in.txt", "r", stdin);
    int u,v,k,t;
    cin >> N >> Q;
	cin >> R >> key;
	intiate();
	for (int i = 0; i < N - 1; i++) {
	    cin >> u >> v >> k;
		construct_persistant_trie(u,v,k);
	}

	int last_answer = 0;

	for (int i = 0; i < Q; i++) {
	    cin >> t;
	    
	    // find real value of t
	    t ^= last_answer;

	    if (t == 0) {
	        cin >> v >> u >> k;
	        // find real values for u, v, and k
	        u ^= last_answer;
	        v ^= last_answer;
	        k ^= last_answer;
	        construct_persistant_trie(u,v,k);
	    }
	    else {
	        cin >> v >> k;
	        // find real values for v, and k
	        v ^= last_answer;
	        k ^= last_answer;
	        // compute the requested values
	        int min_answer = info[v]->get_min_xor(k);
	        int max_answer = info[v]->get_max_xor(k);
	        cout << min_answer << " " << max_answer << endl; 
	        // update last_answer
	        last_answer = min_answer ^ max_answer;  
	    }
	}
    return 0;
}