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
#define MOD                     112272535095293LL
#define MOD1                    172688831471047LL
#define INF                     INT_MAX
#define N                       1000007


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




ll power[N],opower[N];
ll n,k;
string games[100005];
string original;
map<ll,VL> hvalues,morehvalues;
VOLL Q;

void init() {
    power[0] = 1;
    opower[0] = 1;
    for (int i = 1; i < N; ++i) {
        power[i] = power[i-1]*43;
        power[i] %= MOD;
        opower[i] = opower[i-1]*31;
        opower[i] %= MOD1;
    }
    return;
}

inline ll gethash(string &s) {
    ll send = 0,temp;
    temp = s.size();
    for (int i = 0; i < temp; ++i) {
        send = (send*43 + (ll)(s[i]-'a') + 1) % MOD;
    }
    return send;
}

inline ll getnexthash(string &s) {
    ll send = 0,temp;
    temp = s.size();
    for (int i = 0; i < temp; ++i) {
        send = (send*31 + (ll)(s[i]-'a') + 1) % MOD1;
    }
    return send;
}

inline ll compute(ll curVal,ll leave,ll enter) {
    ll send;
    send = rem(43*(curVal-rem(power[k-1]*(original[leave]-'a'+1),MOD)),MOD); 
    send += (original[enter] - 'a' + 1);
    return send % MOD;
}

inline ll computeNext(ll curVal,ll leave,ll enter) {
    ll send;
    send = rem(31*(curVal-rem(opower[k-1]*(original[leave]-'a'+1),MOD1)),MOD1); 
    send += (original[enter] - 'a' + 1);
    return send % MOD1;
}



// main code begins now

int main()
{
    SYNC;
    init();
    cin >> n >> k;
    int m;
    cin >> original;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> games[i];
        ll one = gethash(games[i]);
        ll two = getnexthash(games[i]);
        if(hvalues[one].size() > 0) {
            if(games[hvalues[one].back()] != games[i]) {
                hvalues[one].pb(i);
            }
        }
        else hvalues[one].pb(i);
        if(morehvalues[two].size() > 0) {
            if(games[morehvalues[two].back()] != games[i]) {
                morehvalues[two].pb(i);
            }
        }
        else morehvalues[two].pb(i);
    }
    // cout << hvalues.size() << endl;
    // cout << morehvalues.size() << endl;
    for (int i = 0; i < original.size(); i += k) {
        string cur = original.substr(i,k);
        Q.pb(mp(gethash(cur),getnexthash(cur)));
    }
    for (int i = 0; i < k; ++i) {
        // cout << "for " << i << ":" << endl;
        if(i != 0) {
            for (int j = 0; j < Q.size(); ++j) {
                int Oldstarting = i + j*k - 1;
                int newEnding = (i + j*k + k - 1) % (n*k);
                // cout << Oldstarting << " " << newEnding << endl;
                Q[j].FF = compute(Q[j].FF,Oldstarting,newEnding);
                Q[j].SS = computeNext(Q[j].SS,Oldstarting,newEnding);
            }
            // cout << endl;
        }
        // cout << Q << endl;
        bool allMatched = true;
        map<ll,VL> oneCopy,twoCopy;
        VI answer;
        oneCopy = hvalues;
        twoCopy = morehvalues;
        for (int j = 0; j < Q.size(); ++j) {
            ll xx = -1, yy = -1;
            if(oneCopy[Q[j].FF].size() > 0) {
                xx = oneCopy[Q[j].FF].back();
                oneCopy[Q[j].FF].pop_back();
            }
            if(twoCopy[Q[j].SS].size() > 0) {
                yy = twoCopy[Q[j].SS].back();
                twoCopy[Q[j].SS].pop_back();
            }
            if(xx != yy || xx == -1 || yy == -1) {
                allMatched = false;
                break;
            }
            answer.pb(xx + 1);
        }
        if(allMatched) {
            cout << "YES" << endl;
            for (int j = 0; j < answer.size(); ++j) {
                cout << answer[j] << " ";
            }
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}