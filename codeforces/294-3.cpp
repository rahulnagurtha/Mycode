#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			   ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			   (a-(box(a,b))*b)
#define ceil(a,b) 			  ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			  ((a%b<0)?(((a%b)+b)%b):(a%b))
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
    LL ans=0,mini,maxi;
    LL one,two;
    cin >> one >> two ;
    mini=min(one,two);
    maxi=max(one,two);
    if (2*mini <= maxi) {
    	ans+=mini;
    }
    else {
	    ans+=2*(mini/3);
	    // if (mini>=3) {
	    	maxi=maxi-3*(mini/3);
	    	mini=mini%3;
	    
	    // }

	    if (mini==0)
	    {
	    	/* code */
	    }
	    else if (mini==1)
	    {
	    	// printf("2\n");
	    	if(maxi>=2) ans++;
	    }
	    else {
	    	// printf("3\n");
	    	if(maxi==2 || maxi==3) ans++;
	    	else if(maxi>=4) {
	    		// printf("4\n");
	    		ans+=2;
	    	}
	    }
	}
    cout << ans << endl ;
    return 0;
}