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



int main()
{
    string a,b,c,d,one,two,tmp;
    one = "";
    two = "";
    cin >> a >> b >> c >> d;

    if (a[0] != 'X') {
    	one = a[0];
    }
    if (a[1] != 'X') {
    	one += a[1];
    }
    if (b[1] != 'X') {
    	one += b[1];
    }
    if (b[0] != 'X') {
    	one += b[0];
    }


    if (c[0] != 'X') {
    	two = c[0];
    }
    if (c[1] != 'X') {
    	two += c[1];
    }
    if (d[1] != 'X') {
    	two += d[1];
    }
    if (d[0] != 'X') {
    	two += d[0];
    }
    tmp = (char)two[0];
    tmp += (char)two[1];
    tmp += (char)two[2];
    if(one == tmp) {
    	printf("YES\n");
    	return 0;
    }

    tmp = (char)two[2] ;
    tmp += (char)two[0]; 
    tmp += (char)two[1];
    if(one == tmp) {
    	printf("YES\n");
    	return 0;
    }

    tmp = (char)two[1];
    tmp += (char)two[2];
    tmp += (char)two[0];
    if(one == tmp) {
    	printf("YES\n");
    	return 0;
    }
    printf("NO\n");
    return 0;
}
