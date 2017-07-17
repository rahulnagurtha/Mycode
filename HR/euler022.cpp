#include <bits/stdc++.h>

using namespace std;

int get_score(string src) {
    int retVal = 0;
    for(int i = 0; i < src.size(); i++) {
        retVal += (src[i] - 'A' + 1);
    }
    return retVal;
}

int main() {
    int n,q;
    string tmp;
    cin >> n;
    map<string,int> score;
    vector<string> buffer;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        buffer.push_back(tmp);
    }
    sort(buffer.begin(),buffer.end());
    for(int i = 0; i < n; i++) {
        score[buffer[i]] = get_score(buffer[i])*(i + 1);
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> tmp;
        cout << score[tmp] << endl;
    }
    return 0;
}
