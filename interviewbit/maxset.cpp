#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back

typedef pair<int,int> PII;
typedef long long int ll;


vector<int> Solution::maxset(vector<int> &A) {
    vector<pair<ll,PII> > B;
    vector<int> ans;
    ll tmp = 0;
    int L,R;
    for (int i = 0; i < A.size();) {
        if(A[i] >= 0) {
            tmp = 0;
            L = i;
            while(i < A.size() && A[i] >= 0) {
                tmp += (ll)A[i];
                R = i;
                i++;
            }
            B.push_back(mp(tmp,mp(L,R)));
        }
        else i++;
    }
    tmp = 0;
    L = 0;
    R = -1;
    for (int i = 0; i < B.size(); ++i) {
        if(B[i].FF == tmp && R - L + 1 < B[i].SS.SS - B[i].SS.FF + 1) {
            L = B[i].SS.FF;
            R = B[i].SS.SS;
        }
        else if(B[i].FF > tmp) {
            tmp = B[i].FF;
            L = B[i].SS.FF;
            R = B[i].SS.SS;
        }
    }
    for (int i = L; i <= R; ++i) {
        ans.pb(A[i]);
    }
    return ans;
}