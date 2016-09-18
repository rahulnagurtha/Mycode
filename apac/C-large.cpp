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
#define INF                     INT_MAX
#define N                       100007


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



map<string,set<string> > adjList;
bool isThereACycle;
VS variables;
map<string,int> visited;
map<string,int> T;
map<string,int> lftvariables;


inline void Refresh() {
    adjList.clear();
    variables.clear();
    visited.clear();
    lftvariables.clear();
}


void dfs(string cur) {
	// cout << cur << "->" << endl;
	set<string> adjL = adjList[cur];
	T[cur] = 1;
	visited[cur] = 1;
	for (set<string>::iterator it = adjL.begin(); it != adjL.end(); ++it) {
		if(T[*it] > 0) {
			isThereACycle = true;
			break;
		}
		else if(visited[*it] == 0) {
			dfs(*it);
			if(isThereACycle) break;
		}
	}
	T[cur] = 0;
	return;
}


int main()
{
    int t;
    int testcase = 1;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
        cout << "Case #" << testcase << ": ";
        int n;
        string tmp;
        cin >> n;
        for (int i = 0; i < n; ++i) {
        	cin >> tmp;
        	//process tmp
        	int j = 0;
        	//find equal
        	for (; j < tmp.size(); ++j) {
        		if(tmp[j] == '=') {
        			break;
        		}
        	}
        	string lftVarName = "";
        	for (int one = 0; one < j; ++one) {
        		lftVarName += tmp[one];
        	}
        	// cout << lftVarName << endl;
        	while(tmp[j] != '(') j++;
        	while(j < tmp.size()) {
        		// cout << "cur is " << tmp[j] << endl;
        		if(tmp[j] == ')' || tmp[j] == ',' || tmp[j] == '(') {
        			j++;
        			continue;
        		}
        		string cur = "";
        		while(1) {
        			if(tmp[j] == ',' || tmp[j] == ')') break;
        			cur += tmp[j];
        			j++;
        		}
        		adjList[lftVarName].insert(cur);
        		variables.pb(cur);
        		// cout << cur << endl;
        	}
            lftvariables[lftVarName]++;
        	variables.pb(lftVarName);
        	// cout << adjList[lftVarName] << endl;
        }
        isThereACycle = false;
        for (int i = 0; i < variables.size(); ++i) {
    		if(visited[variables[i]] == 0) {
    			isThereACycle = false;
    			T.clear();
    			dfs(variables[i]);
    			if(isThereACycle) {
	    			break;
	    		}
    		}
    	}
        for (int i = 0; i < variables.size(); ++i) {
            if(adjList[variables[i]].size() == 0) {
                // cout << variables[i] << "-";
                if(lftvariables[variables[i]] == 0) {
                    isThereACycle = true;
                    break;
                }
            }
        }
        // printf("\n");
    	if(!isThereACycle) cout << "GOOD" << endl;
        else cout << "BAD" << endl;
        // cout << answer << endl;
        testcase++;
    }
    return 0;
}