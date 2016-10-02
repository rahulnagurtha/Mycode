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




// main code begins now

int main()
{
    // freopen("in.txt", "r", stdin);
    int n,count ;
    string a[105];
    cin >> n ;
    getchar();
    for (int i = 0; i < n; ++i)
    {
    	getline(cin,a[i]);
    }
    if(n==1) {
    	printf("YES\n");
    	return 0 ;
    }
    for (int i = 0; i < n; ++i)
    {
    	// printf("%d\n",i);
    	for (int j = 0; j < n; ++j)
    	{
    		// printf("here\n");
    		count = 0;
    		if(i!=0 && i!=n-1) {
    			if(j!=0 && j!=n-1) {
    				if(a[i][j-1]=='o') count++;
    				if(a[i][j+1]=='o') count++;
    				if(a[i-1][j]=='o') count++;
    				if(a[i+1][j]=='o') count++;    				
    			}
    			else if(j==0){
    				// if(a[i][j-1]=='o') count++;
    				if(a[i][j+1]=='o') count++;
    				if(a[i-1][j]=='o') count++;
    				if(a[i+1][j]=='o') count++;
    			}
    			else {
    				if(a[i][j-1]=='o') count++;
    				// if(a[i][j+1]=='o') count++;
    				if(a[i-1][j]=='o') count++;
    				if(a[i+1][j]=='o') count++;
    			}

    		}
    		else {
    			if(i==0) {
    				// printf("here1\n");
    				if(j!=0 && j!=n-1) {
	    				if(a[i][j-1]=='o') count++;
	    				if(a[i][j+1]=='o') count++;
	    				// if(a[i-1][j]=='o') count++;
	    				if(a[i+1][j]=='o') count++;    				
	    			}
	    			else if(j==0){
	    				// if(a[i][j-1]=='o') count++;
	    				if(a[i][j+1]=='o') count++;
	    				// if(a[i-1][j]=='o') count++;
	    				if(a[i+1][j]=='o') count++;
	    			}
	    			else {
	    				if(a[i][j-1]=='o') count++;
	    				// if(a[i][j+1]=='o') count++;
	    				// if(a[i-1][j]=='o') count++;
	    				if(a[i+1][j]=='o') count++;
	    			}
    			}
    			else {
    				if(j!=0 || j!=n-1) {
	    				if(a[i][j-1]=='o') count++;
	    				if(a[i][j+1]=='o') count++;
	    				if(a[i-1][j]=='o') count++;
	    				// if(a[i+1][j]=='o') count++;    				
	    			}
	    			else if(j==0){
	    				// if(a[i][j-1]=='o') count++;
	    				if(a[i][j+1]=='o') count++;
	    				if(a[i-1][j]=='o') count++;
	    				// if(a[i+1][j]=='o') count++;
	    			}
	    			else {
	    				if(a[i][j-1]=='o') count++;
	    				// if(a[i][j+1]=='o') count++;
	    				if(a[i-1][j]=='o') count++;
	    				// if(a[i+1][j]=='o') count++;
	    			}
    			}
    		}
    		if(count%2 != 0) {
    			printf("NO\n");
    			return 0;
    		}
    	}
    }
    printf("YES\n");
    return 0;
}