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
typedef vector<VI> VOVI;


vector<int> sindex;
int n,temp,temp1,q;
vector<int>::iterator it;

// main code begins now

int main()
{
    cin >> n ;
    for (int i = 0; i < n; ++i) {
    	cin >> temp;
    	sindex.pb(temp+temp1);
    	temp1 = temp+temp1;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
    	cin >> temp ;
    	it = lower_bound(sindex.begin(),sindex.end(),temp);
    	temp = (it- sindex.begin())+1;
    	cout << temp << endl;
    }
    return 0;
}