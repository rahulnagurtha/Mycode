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
#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                (((a)<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define INF                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;



int main()
{
    int x1,y1,x2,y2;
    int dist;
    cin >> x1 >> y1 >> x2 >> y2 ;
    if (x1 == x2) {
        dist = abs(x1-x2) + abs(y1-y2);
        cout << x1 + dist << " " << y1 << " " << x2 + dist << " " << y2 << endl;
    }
    else if(y1 == y2) {
        dist = abs(x1-x2) + abs(y1-y2);
        cout << x1 << " " << y1 + dist << " " << x2 << " " << y2 + dist << endl;
    }
    else if (((y2-y1) == (x2-x1)) || ((y2-y1) == (x1-x2))) {
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    }
    else {
        printf("-1\n");
    }
    return 0;
}