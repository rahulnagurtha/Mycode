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

#define forup(i,a,b)            for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b)            for(int i = (a); (i) > (b); --(i))
#define rep(i,a)                for(int i = 0; (i) < (a); ++(i))

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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



bool isPrime[10*N];

inline void sieve() {
    fill(isPrime,true);
    isPrime[1] = false;
    for (int i = 2; i < 10*N; ++i) {
        if(!isPrime[i]) continue;
        for (int j = i + i; j < 10*N; j += i) {
            isPrime[j] = false;
        }
    }
    return;
}

// Function to find total number of digits
int countDigits(int n)
{
    int digit = 0;
    while (n > 0) {
        n /= 10;
        digit++;
    }  
    return digit;
}




bool is_left_to_right(int num) {
    while(num > 0) {
        if(!isPrime[num]) return false;
        int digits = countDigits(num);
        num -= (num/(int)pow(10,digits-1))*(int)pow(10,digits-1);
    }
    return true;
}

bool is_right_to_left(int num) {
    while(num > 0) {
        if(!isPrime[num]) return false;
        num /= 10;
    }
    return true;
}



int main()
{
    sieve();
    ll sum = 0;
    int n;
    cin >> n;
    for (int i = 10; i <= n; ++i) {
        if(!isPrime[i]) continue;
        if(is_right_to_left(i) && is_left_to_right(i)) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}