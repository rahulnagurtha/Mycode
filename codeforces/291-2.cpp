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
    LL n,x,y,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,count=0;
    vector<PLL> points;
    bool status[1005];
    // freopen("in.txt", "r", stdin);
    cin >> n >> x >> y ;
    for (int i = 0; i < n; ++i) {
    	status[i]=false;
    }
    for (int i = 0; i < n; ++i) {
    	cin >> temp1 >> temp2 ;
    	points.pb(mp(temp1,temp2));
    }
    temp1=x;
    temp2=y;
    for (int i = 0; i < n; ++i) {
    	if(status[i]==false) {
    		count++;
    		temp3=points[i].first;
    		temp4=points[i].second;
	    	for (int j = 0; j < n; ++j) {
	    		if(status[j]==false) {
	    			temp5=points[j].first;
		    		temp6=points[j].second;
		    		if( (temp6-temp4)*(temp1-temp3)==(temp2-temp4)*(temp5-temp3) ) {
		    			status[j]=true;
		    		}
	    		}
	    	}
	    }
    }
    cout << count << endl ;
    return 0;
}