/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool cmp(Interval lft,Interval ryt) {
    return lft.start <= ryt.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    int lastIdx;
    vector<Interval> ans;
    sort(A.begin(),A.end(),cmp);
    if(A.size() > 0) ans.push_back(A[0]);
    for(int i = 1; i < A.size(); i++) {
        lastIdx = ans.size()-1;
        if(ans[lastIdx].end >= A[i].start) ans[lastIdx].end = max(ans[lastIdx].end,A[i].end);
        else ans.push_back(A[i]);
    }
    return ans;
}
