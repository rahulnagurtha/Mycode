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

#define N 5005


 
struct Occurance
{
    int ID;
    set<int> container;
};

struct Node
{
    int ID;
    VI similar;
}container[110];

bool ec(Occurance &a, Occurance &b) {
    return a.container.size()<b.container.size();
}

bool pc(int &a, int &b) {
    return container[a].similar.size()<container[b].similar.size();
}
 
map<string, int> similar;
int visited[110];
VI onemore[N];


int main()
{
    int n;
    cin>>n;
    int temp,ans=0;
    string s;
    Occurance A[n];
    for (int i = 0; i < n; ++i) {
        cin >> temp >> temp;
        container[i].ID=i;
        for (int j = 0; j < temp; ++j) {
            cin>>s;            
            if(similar.count(s)==0) {            
                similar[s]=similar.size();
            }
            container[i].similar.pb(similar[s]);
        }
        for (int j = 0; j < temp; ++j) {
            onemore[container[i].similar[j]].pb(container[i].ID);
        }
        
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        A[i].ID=i;
        for (int j = 0; j < temp; ++j)
        {
            cin>>s;
            if(similar.count(s)==0)
                similar[s]=similar.size();
            for (int k = 0; k < onemore[similar[s]].size(); ++k)
                A[i].container.insert(onemore[similar[s]][k]);
        }        
    }
    sort(A,A+n,ec);
    for (int i = 0; i < n; ++i)
    {
        VI now(A[i].container.begin(),A[i].container.end());
        sort(now.begin(),now.end(),pc);
        for (int j = 0; j < now.size(); ++j)
        {
            if(visited[now[j]]==0)
            {
                visited[now[j]]=1;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;  
    return 0;
}