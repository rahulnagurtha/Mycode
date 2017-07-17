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
ll sum[10*N];

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

// Rotate function to right rotate the number
int Rotate(int n)
{
    int rem = n % 10;          // find unit place number
    rem *= pow(10, countDigits(n)-1); // to put unit place 
                                    // number as first digit.
    n /= 10;                   // remove unit digit
    n += rem;                  // add first digit to rest
    return n;
}

bool is_circular_prime(int cur) {
	int tmp = cur;
	while(tmp > 0) {
		if(tmp%10 == 0) return false;
		tmp /= 10;
	}
    tmp = cur;
	for (int j = 0; j < 6; ++j) {
    	if(!isPrime[cur]) return false;
    	cur = Rotate(cur);
    }
	return true;
}
 


int main()
{
    sieve();
    sum[0] = 0;
    for (int i = 1; i <= 1000000; ++i) {
    	sum[i] = sum[i-1];
    	if(is_circular_prime(i)) {
            sum[i] += i;
        }
    }
    int n;
    cin >> n;
    cout << sum[n] << endl;
    return 0;
}