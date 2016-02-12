#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
vector<LL> asn[10]; LL sum[10];

bool swapp() {
    int id = max_element(sum, sum + 10) - sum;
    LL minsum = sum[id];
    PII x, y;
    for (int i = 0; i < asn[id].size(); i++) {
        for (int j = 0; j < 10; j++) {
            if (j == id) continue;
            for (int k = 0; k < asn[j].size(); ++k) {
                LL d = asn[id][i] - asn[j][k];
                if (max(sum[id] - d, sum[j] + d) < minsum) {
                    minsum = max(sum[id] - d, sum[j] + d);
                    x = make_pair(id, i), y = make_pair(j, k);
                }
            }
        }
    }
    if (minsum != sum[id]) {
        sum[x.first] -= asn[x.first][x.second] - asn[y.first][y.second];
        sum[y.first] += asn[x.first][x.second] - asn[y.first][y.second];
        swap(asn[x.first][x.second], asn[y.first][y.second]);

        return true;
    }
    return false;
}

LL bitmask[2][1<<16];

bool subset() {
    memset(bitmask, 0, sizeof bitmask);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (1 << asn[i].size()); j++) {
            for(int it = 1, ind = 0; it <= j; it <<= 1, ind++) {
                if (it & j) {
                    bitmask[i][j] += asn[i][ind];
                }
            }
        }
    }

    int id = max_element(sum, sum + 2) - sum;
    LL minsum = sum[id];
    PII x, y;
    for (int b1 = 0; b1 < (1 << asn[id].size()); b1++) {
        for (int j = 0; j < 2; j++) {
            if (j == id) continue;
            for (int b2 = 0; b2 < (1 << asn[j].size()); b2++) {
                LL d = bitmask[id][b1] - bitmask[j][b2];
                if (max(sum[id] - d, sum[j] + d) < minsum) {
                    minsum = max(sum[id] - d, sum[j] + d);
                    x = make_pair(id, b1), y = make_pair(j, b2);
                }
            }
        }
    }

    if (minsum == sum[id]) return false;
    bitset<16> b1(x.second), b2(y.second);
    vector<LL> v1, v2;

    for (int i = 0; i < asn[x.first].size(); i++) {
        if (b1.test(i)) {
            v2.push_back(asn[x.first][i]);
        } else {
            v1.push_back(asn[x.first][i]);
        }
    }

    for (int i = 0; i < asn[y.first].size(); i++) {
        if (b2.test(i)) {
            v1.push_back(asn[y.first][i]);
        } else {
            v2.push_back(asn[y.first][i]);
        }
    }

    asn[x.first] = v1;
    asn[y.first] = v2;

    sum[x.first] = accumulate(v1.begin(), v1.end(), 0LL);
    sum[y.first] = accumulate(v2.begin(), v2.end(), 0LL);

    // cout << x.first << ' ' << x.second << ' ' << bitmask[x.first][x.second] << endl;
    // cout << y.first << ' ' << y.second << ' ' << bitmask[y.first][y.second] << endl;
    return true;
}

int main() {
	srand(714602);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("in.in","r",stdin);
    // freopen("ans.txt", "w", stdout);
#endif
    const int n = 100;
    LL w[101];
    map<LL, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        mp[w[i]] = i;
    }
    sort(w, w + n, greater<LL>());
    //vector<LL> asn[10];
    //LL sum[10];
    memset(sum, 0, sizeof sum);
    // cout << accumulate(w, w + n, 0LL) << endl;
    set<LL> xz(w, w + 100);
    // for (int i = 0; i < n; i++) {
    //     int id = -1;
    //     LL mn = (1LL) << 62;
    //     for (int j = 0; j < 10; j++) {
    //         if (sum[j] < mn) {
    //             mn = sum[j];
    //             id = j;
    //         }
    //     }
    //     asn[id].push_back(w[i]);
    //     sum[id] += w[i];
    // }
    for (int i = 0; i < 100; ++i) {
    	int id = rand()%2;
    	asn[id].push_back(w[i]);
    	sum[id] += w[i];
    }
    // while(swapp());
    // cout << endl << endl;
//    for (int i = 0; i < 10; i++) {
//        // cout << sum[i] << ' ';
//        for(LL& z: asn[i]) {
//            cout << mp[z] << ' ';
//        }
//        cout << endl;
//    }


    for (int i = 0; i < 40; i++) {
        bool f = subset();
        if (!f) {
            // cout << i << endl;
            break;
        }
    }
//    for (int i = 0; i < 10; i++) {
//        assert(sum[i] == accumulate(asn[i].begin(), asn[i].end(), 0LL));
//    }
//    cout << endl << endl;
//    for (int i = 0; i < 10; i++) {
//        cout << sum[i] << ' ';
//        for(LL& z: asn[i]) {
//            cout << z << ' ';
//        }
//        cout << endl;
//    }

    set<int> st;
    // cout << endl << endl;
    for (int i = 0; i < 2; i++) {
        cout << sum[i] << ' ';
        vector<int> op;
        for(LL& z: asn[i]) {
            op.push_back(mp[z]);
            st.insert(mp[z]);
        }
        sort(op.begin(), op.end());
        for (int z: op) {
            cout << z << ' ';
        }
        cout << endl;
    }
    return 0;
}
