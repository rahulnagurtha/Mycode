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
    TrieNode* children[10];
    // Initialize your data structure here.
    TrieNode() {
        prefixes = 0;
        for (int i = 0;i < 10;i++){
            children[i] = NULL;
        }
    }
};


class Trie {
public:
    TrieNode* root;
    string pattern;
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
            current = current->children[word[i]-'0'];
            current->prefixes--;
        }
        return;
    }

    //maximum Xor with the current string
    int query(int pos,TrieNode *curNode) {
        if(curNode->prefixes == 0) return 0;
        if(pos == 18) return curNode->prefixes;
        // cout << pattern[pos] << endl;
        int ans = 0;
        if(pattern[pos] == '0') {
            for (int i = 0; i < 10; i += 2) {
                if(curNode->children[i] != NULL) 
                    ans += query(pos+1,curNode->children[i]);
            }
        }
        else {
            for (int i = 1; i < 10; i += 2) {
                if(curNode->children[i] != NULL) 
                    ans += query(pos+1,curNode->children[i]);
            }
        }
        return ans;
    }
    int go(string word) {
        pattern = word;
        return query(0,root);
    }
};



string toString(ll num) {
    string ans;
    while(num > 0) {
        ans = (char)(num%10 + '0') + ans;
        num = num/10;
    }
    while(ans.size() < 18) ans = '0' + ans;
    return ans;
}

Trie Multiset;

int main()
{
    // Multiset.insert(toString(0));
    ll q,x;
    string tmp;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> tmp;
        if(tmp == "+") {
            cin >> x;
            Multiset.insert(toString(x));
        }
        else if(tmp == "-") {
            cin >> x;
            Multiset.removeWord(toString(x));
        }
        else {
            cin >> tmp;
            while(tmp.size() < 18) tmp = '0' + tmp;
            cout << Multiset.go(tmp) << endl;
        }
    }
    return 0;
}