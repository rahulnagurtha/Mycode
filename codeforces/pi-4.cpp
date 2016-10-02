#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define FF                      first
#define SS                      second

int main()
{
    map<int,int> data;
    map<int,int>::iterator itlow;
    int n,k,a,m,tmp,ans;
    si3(n,k,a);
    si(m);
    data.insert(pair<int,int>(1,n));
    ans = (n+1)/(a+1);
    for (int i = 0; i < m; ++i) {
        si(tmp);
        itlow = data.lower_bound(tmp);
        if(itlow == data.end()) itlow--;
        if(itlow->FF == tmp) {
            ans -= ((itlow->SS) - (itlow->FF) + 2)/(a+1);
            if(itlow->FF != itlow->SS) {
                ans += ((itlow->SS) - (itlow->FF) + 1)/(a+1);
                data.insert(pair<int,int>(tmp+1,itlow->SS));
            }
            if(ans < k) {
                printf("%d\n",i+1);
                return 0;
            }
            data.erase(itlow);
        }
        else {
            if(itlow->FF > tmp) itlow--;
            ans -= ((itlow->SS) - (itlow->FF) + 2)/(a+1);
            ans += ((itlow->SS) - (tmp+1) + 2)/(a+1) + ((tmp-1) - (itlow->FF) + 2)/(a+1);
            if(ans < k) {
                printf("%d\n",i+1);
                return 0;
            }            
            data.insert(pair<int,int>(tmp+1,itlow->SS));
            itlow->SS = tmp-1;
        }
    }
    printf("-1\n");
    return 0;
}