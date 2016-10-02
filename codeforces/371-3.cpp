#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,ll> a;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin >> s;
        ll n,i;
        cin >> n;
        ll temp = 0,j = 0;
        while(n) {
            if(n % 2) temp += (1LL<<j);
            n /= 10;
            j++;
        }
        if(s[0] == '+') a[temp]++;
        else if(s[0]=='-') a[temp]--;
        else cout << a[temp] << endl;

    }

return 0;
}