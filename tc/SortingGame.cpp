#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back

typedef long long int ll;
typedef vector<int> VI;

class SortingGame
{
public:
    set<ll> visited;
    ll pow[10];
    void init() {
        pow[0] = 1;
        for (int i = 1; i < 10; ++i) {
            pow[i] = pow[i]*37;
        }
    }
    inline ll hashValue(vector<int> key) {
        ll val = 0;
        for (int i = 0; i < key.size(); ++i) {
            val += pow[i+1]*key[i];
        }
        return val;
    }
    VI afterRotation(VI tmp,int idx,int k) {
        int l = idx,r = idx + k - 1;
        while(l < r) {
            swap(tmp[l],tmp[r]);
            l++;
            r--;
        }
        return tmp;
    }
    inline bool isSorted(VI tmp) {
        int pre = tmp[0];
        for (int i = 1; i < tmp.size(); ++i) {
            if(pre > tmp[i]) return false;
            pre = tmp[i];
        }
        return true;
    }
    int fewestMoves(vector<int> board,int k) {
        init();
        ll hashNxtConfig;
        deque<pair<ll,int>,bool> > Q;
        pair<vector<int>,int> curConfig;
        vector<int> nextConfig;
        curConfig.FF = board;
        curConfig.SS = 0;
        visited.insert(hashValue(curConfig.FF));
        Q.pb(mp(board,0));
        while(!Q.empty()) {
            curConfig = Q.front();
            Q.pop_front();
            if(isSorted(curConfig.FF)) return curConfig.SS;
            for (int i = 0; i + k <= curConfig.FF.size(); ++i) {
                nextConfig = afterRotation(curConfig.FF,i,k);
                hashNxtConfig = hashValue(nextConfig);
                if(visited.find(hashNxtConfig) == visited.end()) {
                    visited.insert(hashNxtConfig);
                    Q.pb(mp(nextConfig,curConfig.SS+1));
                }
            }
        }
        return -1;
    }
};