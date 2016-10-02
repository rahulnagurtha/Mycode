#include <bits/stdc++.h>
 
using namespace std;
 
 
 
 
// main code begins now
 
int main()
{
    
    int b[100005],m,n,temp1,temp2;
    long long int sum=0;
    // memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin >> n ;
    char op;
    for (int i = 1; i <= n; ++i) {
        cin >> temp1 >> temp2 ;
        b[temp1]+=temp2;
    }
    cin >> m ;
    for (int i = 0; i < m; ++i) {
        cin >> op >> temp1 ;
        if(op == '+') {
            b[temp1]++;
        }
        else if(op == '-') {
            b[temp1]--;
        }
        else {
            for (int i = 1; i < 100001; ++i) {
                sum+=b[i]*(temp1%i);
            }
            cout << sum << endl ;
        }
        sum=0;
    }
    return 0;
} 