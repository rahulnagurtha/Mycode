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

int b[200];

int main()
{
    // freopen("in.txt", "r", stdin);
    int n,flag=0;
    string a;
    cin >> n ;
    getchar();
    cin >> a;

    for (int i = 0; i < a.size(); ++i) {
    	b[a[i]]++;
    }
    for (int i = 0; i < 26; ++i) {
    	if(b[65+i]==0 && b[97+i]==0) {
    		flag=1;
    		break;
    	}
    }
    if (flag==1)
    {
    	printf("NO\n");
    }
    else printf("YES\n");
    return 0;
}