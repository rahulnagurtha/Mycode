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
    int t[100];
    string temp;
    cin >> temp ;
    for (int i = 0; i < temp.size(); ++i) {
    	t[i]=temp[i]-48;
    }
    for (int i = 0; i < temp.size(); ++i) {
    	if(i==0) {
    		if(t[i]!=9) t[i]=min(9-t[i],t[i]);
    	}
    	else t[i]=min(9-t[i],t[i]);
    }
    for (int i = 0; i < temp.size(); ++i) {
    	cout << t[i] ;
    }
    printf("\n");
    
    return 0;
}