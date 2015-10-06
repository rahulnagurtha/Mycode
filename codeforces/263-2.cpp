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
    int n,k,temp;
    LL ans;
    ans=0;
    // priority_queue<pair<char,int>,vector<pair<char,int> >, greater<pair<char,int> > > data;
    map<char,int > data;
    string input ;
    priority_queue<int,vector<int>,less<int> > order;
    cin >> n >> k ;
    getchar();
    getline(cin , input);
    for (int i = 0; i < 26; ++i)
    {
    	data[65+i]=0;
    }
    for (int i = 0; i < n; ++i)
    {
    	// printf("%c\n",input[i]);
    	data[input[i]]++;	
    }
    // for (int i = 0; i < 26; ++i)
    // {
    // 	// order.push(data[65+i]);
    // 	printf("%d\n",data[65+i] );
    // }
    for (int i = 0; i < 26; ++i)
    {
    	order.push(data[65+i]);
    }
    while(k>0) {
    	temp = order.top();
    	// printf("temp is %d\n",temp);
    	if(k>=temp) ans += (LL)temp*temp;
    	else ans+= (LL)k*k;
    	k -= temp ;
    	order.pop();
    }
    cout << ans << endl ;
    return 0;
}