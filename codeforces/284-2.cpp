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
    int n,m;
    string temp1,temp2;
    map<string,string>::iterator it1,it2 ;
    vector<string> input;
    vector<string> output;
    map<string,string> firstf,secondf;
    // freopen("in.txt", "r", stdin);
    cin >> n >> m ;
    for (int i = 0; i < m; ++i) {
    	cin >> temp1 >> temp2 ;
    	firstf[temp1]=temp2;
    	secondf[temp2]=temp1;
    }
    for (int i = 0; i < n; ++i) {
    	cin >> temp1 ;
    	input.pb(temp1);	
    }
    for (int i = 0; i < n; ++i) {
    	it1=firstf.find(input[i]);
    	it2=firstf.find(input[i]);
    	if (it1!=firstf.end()) {
    		temp1=it1->second;
    		temp2=input[i];
    		if(temp1.size() >= temp2.size() ) output.pb(temp2);
    		else output.pb(temp1);
    	}
    	else {
    		temp1=it2->second;
    		temp2=input[i];
    		if(temp1.size() >= temp2.size() ) output.pb(temp2);
    		else output.pb(temp1);
    	}
    }
    for (int i = 0; i < output.size(); ++i) {
    	cout << output[i] << " " ;
    }
    printf("\n");
    return 0;
}