#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int,int>&i, const pair<int,int>&j)
{
    return i.first < j.first;
    if(i.first == j.first) return (i.second < j.second);
}
// main code begins now

int main()
{
    
    int n,k,max;
    int a[100005];
    cin >> n >> k ;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] ;
    }
    max=a[0];
    for (int i = 0; i < n; ++i)
    {
        if(a[i]>max) max=a[i];
    }
    if(k%2==0) {
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << " " ;

        }
    }
    else {
        for (int i = 0; i < n; ++i)
        {
            cout << max-a[i] << " " ;
        }
    }
    return 0;
}