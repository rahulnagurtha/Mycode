class Solution {
public:
    string countAndSay(int n);
};

inline string toString(int i) {
    string s;
    if(i == 0) return s = "0";
    while(i > 0) {
        s = (char)('0' + i%10) + s;
        i = i/10;
    }
    return s;
}

string Solution::countAndSay(int A) {
    int cnt;
    char cur;
    string tmp;
    string ans = "1";
    for (int i = 2; i <= A; ++i) {
        cnt = 1;
        tmp = ans;
        ans = "";
        cur = tmp[0];
        for (int j = 1; j < tmp.size(); ++j) {
            if(tmp[j] != tmp[j-1]) {
                ans += toString(cnt) + cur;
                cur = tmp[j];
                cnt = 1;
            }
            else cnt++;
        }
        ans += toString(cnt) + cur;
    }
    return ans;
}