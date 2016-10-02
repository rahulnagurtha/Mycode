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
    LL n,r,avg,atmax,count=0,temp1,temp2,sum=0,needed;
    VOLL marks;
    // freopen("in.txt", "r", stdin);
    cin >> n >> r >> avg ;
    for (int i = 0; i < n; ++i) {
    	cin >> temp1 >> temp2 ;
    	sum+=temp1;
    	marks.pb(mp(temp2,temp1));
    }
    if(sum >= n*avg) {
    	printf("0\n");
    }
    else {
    	needed=n*avg-sum;
    	sort(marks.begin(),marks.end());
    	for (int i = 0; i < n; ++i) {
    		if(marks[i].second < r) {
    			atmax=r-marks[i].second;
    			
    			if(needed>atmax) {
    				count+=(marks[i].first)*atmax;
    				needed-=atmax;
    			}
    			else {
    				count+=(marks[i].first)*(needed);
    				break;
    			}
    		}
    	}
    	cout << count << endl ;
    }
    return 0;
}