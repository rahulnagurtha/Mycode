#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif

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
typedef   double ld;
int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};





inline void Refresh() {
    
}

const ll MAX=1000000;
ld answer1[MAX+10];
ld answer2[MAX+10];
int main()
{
	ll i,j,k,x,m;
    int t;
    ld p;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
 			cin>>m>>p>>x;
 			answer1[0]=0;
 			answer1[MAX]=1;
 				j=MAX/2;
 			for(i=j;i<MAX;i++)
 				answer1[i]=p;
 			for(i=1;i<j;i++)
 				answer1[i]=0;

 			for(j=2;j<=m;j++)
 			{
 				 cout<<j<<endl;
 				ld p1;
 				for(i=1;i<MAX;i++)
	 			{

	 				ll z=2*i;
	 				if(z<MAX)
	 				{
	 					p1=p*answer1[z];
	 				}
	 				else if(z==MAX)
	 				{
	 					p1=p;
	 				}
	 				else if(z>MAX)
	 				{
	 					ll diff=MAX-i;
	 					p1=(1.00000-p)*answer1[i-diff];
	 					p1+=p;
	 				}
	 				if(i==x)
	 				{
	 					cout<<j<<" "<<p1<<endl;
	 				}
	 				answer2[i]=p1;
	 			}
	 			for(i=1;i<MAX;i++)
	 			{
	 				answer1[i]=answer2[i];
	 				
	 			}
	 			answer1[0]=0;
	 			answer1[MAX]=1;
 			}
 			printf("%lf\n",answer1[x]);
 			
    }
    return 0;
}