#include <bits/stdc++.h>

using namespace std;



#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			    ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			    (a-(box(a,b))*b)
#define ceil(a,b) 			    ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			    ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;



LL a[300005],ans=0;
// main code begins now

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    
    cin >> n ; 
    for (int i = 0; i < n; ++i)
    {
    	cin >> a[i] ;
    }
    // printf("here\n");
    sort(a,a+n);
    // if(n==1) {
    // 	cout << a[0] << endl ;
    // 	return 0;
    // }
    // if(n==2) {
    // 	cout << a[0] << endl ;
    // 	return 0;
    // }
    for (int i = 0; i < n; ++i)
    {
    	// printf("here\n");
    	ans += (i+2)*a[i];
    }
    ans -=a[n-1];
    cout << ans << endl ;
    return 0;
}