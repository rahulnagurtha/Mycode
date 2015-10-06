#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define N 5123
#define sd(x) scanf("%d", &x)
#define F first
#define S second
#define PB push_back

int str[N]; //input
int rank[N], pos[N]; //output
int cnt[N], next[N]; //internal
bool bh[N], b2h[N];
 
// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b) {
    return str[a] < str[b];
}
 
void suffixSort(int n) {
  //sort suffixes according to their first characters
    for(int i=0; i<n; ++i) {
        pos[i] = i;
    }
    sort(pos, pos + n, smaller_first_char);
    //{pos contains the list of suffixes sorted by their first character}
 
    for (int i=0; i < n; ++i) {
        bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
        b2h[i] = false;
    }
 
    for (int h = 1; h < n; h <<= 1) {
    //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
        int buckets = 0;
        for (int i=0, j; i < n; i = j) {
            j = i + 1;
            while (j < n && !bh[j]) j++;
            next[i] = j;
            buckets++;
        }
        if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing strings starting with the same h characters}
 
        for (int i = 0; i < n; i = next[i]) {
            cnt[i] = 0;
            for (int j = i; j < next[i]; ++j) {
                rank[pos[j]] = i;
            }
        }
 
        cnt[rank[n - h]]++;
        b2h[rank[n - h]] = true;
        for (int i = 0; i < n; i = next[i]) {
            for (int j = i; j < next[i]; ++j) {
                int s = pos[j] - h;
                if (s >= 0) {
                    int head = rank[s];
                    rank[s] = head + cnt[head]++;
                    b2h[rank[s]] = true;
                }
            }
            for (int j = i; j < next[i]; ++j) {
                int s = pos[j] - h;
                if (s >= 0 && b2h[rank[s]]) {
                    for (int k = rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                }
            }
        }
        for (int i=0; i<n; ++i) {
            pos[rank[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i=0; i<n; ++i) {
        rank[pos[i]] = i;
    }
}

int height[N];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0
void getHeight(int n) {
    for (int i=0; i<n; ++i) rank[pos[i]] = i;
    height[0] = 0;
    for (int i=0, h=0; i<n; ++i){
        if (rank[i] > 0) {
            int j = pos[rank[i]-1];
            while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
            height[rank[i]] = h;
            if (h > 0) h--;
        }
    }
}

bool can[N][N];
string s;
int a[N];

int main() {
    int n, i, p, j, k, l, q;
    cin>>s>>p;
    n = s.length();
    for(i = 0; i < n; i++){
        str[i] = s[i];
    }
    suffixSort(n);
    getHeight(n);
    for(i = 0; i < n; i++){
        //cout<<i<<" "<<pos[i]<<" "<<height[i]<<endl;
    }
    s = s + "$";
    for(i = 0; i < n; i++){
        can[i][i] = true;
        can[i][i + 1] = (s[i] == s[i + 1]);
    }
    for(i = 0; i + 2 < n; ++i){
        can[i][i + 2] = (s[i] == s[i + 2]);
        can[i][i + 3] = (s[i] == s[i + 3]);
    }
    for(l = 4; l < n; l++){
        for(i = 0; i + l < n; ++i){
            can[i][i + l] = (can[i + 2][i + l - 2] && s[i] == s[i + l]);
            can[i][i + l + 1] = (s[i] == s[i + l + 1] && can[i + 2][i + l - 1]);
        }
    }
    height[0] = 0;
    height[n] = 0;
    for(i = 0; i < n; i++){
        j = pos[i];
        a[i + 1] = height[i + 1];
        for(q = i + 2; q <= n; q++){
            a[q] = min(height[q], a[q - 1]);
        }
        /*cout<<i<<" "<<height[i]<<" ";
        for(q = i + 1; q <= n; q++){
            cout<<a[q]<<" ";
        }
        cout<<endl;*/
        q = n;
        for(k = j + height[i]; k < n; k++){
            while(q > i){
                if(a[q] >= k - j + 1){
                    break;
                }
                q--;
            }
            //cout<<" "<<k<<" "<<q<<" "<<a[q]<<endl;
            if(can[j][k] == true){
                //cout<<i<<" "<<j<<" "<<k<<" "<<q<<endl;
                p -= q - i + 1;
                if(p <= 0){
                    for(l = j; l <= k; ++l){
                        printf("%c", s[l]);
                    }
                    return 0;
                }
            }
        }
    }
                
    return 0;
}