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

int n,m;
int score,num;
string surname;
vector<vector<pair<int,string> > > region(10005);


int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> surname >> num >> score;
        region[num].pb(mp(score,surname));
    }
    for (int i = 1; i <= m; ++i) {
        sort(region[i].begin(),region[i].end());
    }
    for (int i = 1; i <= m; ++i) {
        if (region[i].size() > 2) {
            if(region[i][region[i].size()-2].FF == region[i][region[i].size()-3].FF) {
                cout << "?" << endl;
            }
            else {
                cout << region[i][region[i].size()-1].SS << " " << region[i][region[i].size()-2].SS << endl;   
            }
        }
        else {
            cout << region[i][region[i].size()-1].SS << " " << region[i][region[i].size()-2].SS << endl;
        }
    }
    return 0;
}
