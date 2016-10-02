typedef long long int ll;

int Solution::sqrt(int A) {
    if(A == 0) return 0;
    ll lft = 1;
    ll ryt = A;
    ll mid;
    while(lft <= ryt) {
        if(ryt - lft <= 2) {
            for(ll i = ryt;i >= lft;i--) {
                if(i*i <= (ll)A) return (int)i;
            }
        }
        mid = (lft + ryt)/2;
        if(lft == ryt) return (int)lft;
        else if(mid*mid <= (ll)A) lft = mid;
        else ryt = mid - 1;
    }
}