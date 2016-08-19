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

map<string, int> City;
int v[21], reached[21];
VOII graph[21];
VI temp;
 
void recurse(int c, int ASS , VI container){
    if(ASS  + v[c]<=96)
    {    
    	int i;       
        container.pb(c);
        reached[c]=1;      
        ASS +=v[c];
        if(container.size()>temp.size()) temp.clear(), temp=container;         
        for (int i = 0; i < graph[c].size(); ++i)
        {
            if(!reached[graph[c][i].SS] && graph[c][i].FF<=16)
            {
                if(ASS +graph[c][i].FF<=(ASS /16+1)*16)
                	recurse(graph[c][i].SS, ASS +graph[c][i].FF, container);
                else
                	recurse(graph[c][i].SS, (ASS /16+1)*16+graph[c][i].FF, container);
            }
        }
        container.pop_back();
        reached[c]=0;
    }
}


int main()
{

    int n;
    int e,a,b,w;
    string s,name;
    vector<string> ss;
    cin >> n;
    City["Bevagna"]=1;
    fill(reached,0);
    ss.pb("");
    ss.pb("Bevagna");
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {        
        getline(cin,s);        
        name=s.substr(0,s.find(","));
        if(City.find(name)==City.end()) City[name]=City.size(),ss.pb(name);
        v[City[name]]=stoi(s.substr(s.find(",")+1));
    }
    cin>>e;
    cin.ignore();
    for (int i = 0; i < e; ++i)
    {
        getline(cin,s);
        name=s.substr(0,s.find(","));
        a=City[name];
        s.erase(0,s.find(",")+1);
        name=s.substr(0,s.find(","));
        b=City[name];
        w=stoi(s.substr(s.find(",")+1));
        graph[a].pb(mp(w,b));
        graph[b].pb(mp(w,a));
    }        
    recurse(1,0,VI ());
    if(temp.size()>1) for (int i = 1; i < temp.size(); ++i) cout << ss[temp[i]] << endl;
    else cout << "NONE";
    return 0;
}