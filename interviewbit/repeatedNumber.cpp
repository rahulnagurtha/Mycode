typedef long long int ll;

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    ll sum = 0;
    ll sqSum = 0;
    ll N = A.size();
    for(int i = 0 ;i < A.size() ;i++) {
        sum += A[i];
        sqSum += (ll)A[i]*(ll)A[i];
    }
    ll difference = sum - (N*(N+1))/2;
    ll sqDifference = sqSum - (N*(N+1)*(2*N+1))/6;
    sum = sqDifference/difference;
    ll a = (sum + difference)/2;
    ll b = (sum - difference)/2;
    vector<int> ans;
    ans.push_back(int(a));
    ans.push_back(int(b));
    return ans;
}
