#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
        int price,a[5],sum,flag=0;
        cin >> price >> a[0] >> a[1] >> a[2] >> a[3];
        for (int i = 0; i < 16 ; ++i) {
            sum=0;
            for (int j = 0; j < 4 ; ++j) {
                if( (1 << j) & i ) sum+=a[j];
            }
            if(sum==price) {
                flag=1;
                printf("possible\n");
                break;
            }
        }
        if(flag==0) printf("noo\n");
    }
    return 0;
}