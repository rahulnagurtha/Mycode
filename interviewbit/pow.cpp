typedef long long int ll;

#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))

int Solution::pow(int x, int n, int d) {
    if(x == 0 && n == 0) return 0;
    ll ans = 1;
    ll a = x;
    ll b = n;
    ll mod = d;
    while(b > 0) {
        if(b%2 != 0) ans = rem(ans*a,mod);
        a = rem(a*a,mod);
        b = b/2;
    }
    return (int)(ans);
}