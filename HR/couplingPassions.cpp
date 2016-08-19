#include <bits/stdc++.h>

using namespace std;

#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define PI         	 			3.1415926535897932384626
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};


#define N 300005

VI g[N];

double R = 6371.0;

struct node
{
	double lat, lon;
	string ID;
	set<string> info;
}location[N];

double initialise(double X) {
	return X*PI/180.0;
}

double function_find(node ptt1,node ptt2)
{
    double ptt1_lat  = initialise(ptt1.lat);
    double ptt2_lat  = initialise(ptt2.lat);
    double ptt1_long  = initialise(ptt1.lon);
    double ptt2_long  = initialise(ptt2.lon);

    return acos( sin( ptt1_lat ) * sin( ptt2_lat ) + cos( ptt1_lat ) * cos( ptt2_lat ) *cos( ptt2_long - ptt1_long) ) * R;
}

int main()
{
	int n;
	cin>>n;
	string s;
	map<string, int> INDEX;
	int temp=n,m;
	while(temp--)
	{
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> s;
			INDEX[s] = 1;
		}
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {		
		cin >> location[i].ID >> location[i].lat >> location[i].lon >> temp;
		while(temp--)
		{
			cin >> s;
			location[i].info.insert(s);
		}
	}
	int ans = 0;
	double dis = -1;
	set<string> tem, final;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			int now = 0;
			tem.clear();
			for (auto it = location[i].info.begin(); it != location[i].info.end() ; ++it) 
				if(INDEX[*it]==1) tem.insert(*it);
			for (auto it = location[j].info.begin(); it != location[j].info.end() ; ++it) 
				if(INDEX[*it]==1) tem.insert(*it);
			now = tem.size();
			if (now>ans)
				final.clear(), final.insert(location[i].ID),
				final.insert(location[j].ID),
				dis = function_find(location[i], location[j]), ans = now;
			else if (now==ans and (dis>function_find(location[i], location[j]) or dis<0))
				dis = function_find(location[i], location[j]),
				final.clear(), final.insert(location[i].ID),
				final.insert(location[j].ID), ans = now;
		}
	}
	for (auto it = final.begin(); it != final.end() ; ++it) 
		cout << *it << " ";
	return 0;
}