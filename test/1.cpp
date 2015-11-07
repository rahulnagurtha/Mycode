#include <bits/stdc++.h>

#define scl(t) scanf("%ld",&t)
#define sc(t) scanf("%d",&t)
#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define lc printf("\n")


using namespace std;



ll dp[110][110][2];


int main()
{


    int t,ind,n,k,i,j,b;
    ll ans;
    sc(t);
    while(t--)
    {
        sc(ind);sc(n);sc(k); // taking input
        for(i=0;i<n;i++)
            for(j=0;j<=k;j++)
                for(b=0;b<2;b++)
                    dp[i][j][b]=0; //initialising the array with all 0

         /* no of ways of constructing a string of length 1 with adjbc()=0 is 1
             for b=0 and b=1 */

         dp[1][0][0]=dp[1][0][1]=1; //base case
        for(i=2;i<=n;i++)
        {
            for(j=0;j<=k;j++)
            {

                    dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
                    if(j>0)
                        dp[i][j][1]=dp[i-1][j-1][1];
                    dp[i][j][1]+=dp[i-1][j][0];

            }
        }
        ans=dp[n][k][0]+dp[n][k][1];
        cout<<ind<<" "<<ans<<endl;
    }

}
