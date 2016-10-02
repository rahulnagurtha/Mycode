#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;



template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }

template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }

template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }

template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }



VOVI graph(100005);
int n,m,temp,out,in,answer;
bool cat[100005];
int parent[100005];
int total[100005];
bool status[100005];

// main code begins now

void dfs(int foo) {
	if(total[parent[foo]] > m) total[foo] = m + 1;
	else {
		if(cat[foo]) total[foo] = total[parent[foo]] + 1;
		else total[foo] = 0;
	}
	for (int it = 0; it < graph[foo].size() ; ++it) {
		if (status[graph[foo][it]] == false) {
   			status[graph[foo][it]] = true;
   			parent[graph[foo][it]] = foo;
    		dfs(graph[foo][it]);
    	}
	}
}


void evaluate() {
	answer = 0;
	for (int i = 2; i <= n; ++i) {
		if(graph[i].size() == 1 && total[i] <= m) answer++;
	}
	pi(answer);
	return;
}

int main()
{
	fill(status,false);
	status[1] = true;
	parent[1] = 0;
    total[0] = 0;
    si2(n,m);
    for (int i = 1; i <= n; ++i) {
    	si(temp);
    	cat[i] = temp;
    }
    for (int i = 1; i < n; ++i) {
    	si2(out,in);
    	graph[out].pb(in);
    	graph[in].pb(out);
    }
    dfs(1);
    evaluate();
    return 0;
}