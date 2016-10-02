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
    LL n,x,count=0,pre1,pre2,temp1,temp2;
    VOII moments;
    cin >> n >> x ;
    for (int i = 0; i < n; ++i) {
    	cin >> temp1 >> temp2 ;
    	moments.pb(mp(temp1,temp2));
    }
    sort(moments.begin(),moments.end());
  	count+=(moments[0].first-1)%x;
	pre1=0;
    for (int i = 0; i < n; ++i) {
    	temp1=moments[i].first;
    	temp2=moments[i].second;	
    	count+=temp2-temp1+1;
    	if(pre1!=0) {
    		if( (temp1 - pre1 - 1) >= x) {
	    		count+=(temp1 - pre1-1)%x;
	    	}
	    	else count+=temp1 - (pre1 + 1);
    	}
    	pre1=temp2;
    }
    cout << count << endl ;
    return 0;
}