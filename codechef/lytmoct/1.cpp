#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    int t;
    cin >> t ;
    while(t--) {
        int n,m,x,y,flag[30],temp=0;
        for (int i = 0; i < 30; ++i) {
            flag[i]=1;
        }
        vector<pair<int,int> > v;
        cin >> n >> m ;
        for (int i = 0; i < m ; ++i) {
            cin >> x >> y ;
            v.push_back(make_pair(x,y));
        }
        if(m==0||n==1) {
            printf("YES\n");
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j= 0; j < m; ++j) {
                if(!(v[j].first==i || v[j].second==i)) {
                    flag[i]=0;
                    break;
                }
            }
        }
        for (int i = 1; i <= n ; ++i) {
            if(flag[i]==1) {
                printf("YES\n");
                temp=1;
                break;
            }
        }
        if (temp==0) {
            printf("NO\n");
        }
    }
    return 0;
}