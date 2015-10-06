#include <bits/stdc++.h>

using namespace std;

int search(vector<int> A, int B) {
    vector<int>::iterator low;
    if(A.size() <= 4) {
        for (int i = 0; i < A.size(); ++i) {
            if(A[i] == B) return i;
        }
        return -1;
    }
    int lft = 0,ryt = A.size()-1,mid,pos,ans,flag = 0;
    while(ryt - lft >= 4) {
        if(A[lft] < A[ryt]) {
            flag = 1;
            pos = lft;
            break;
        }
        mid = (lft + ryt)/2;
        if(A[mid] < A[lft]) ryt = mid;
        else lft = mid+1;
    }
    if(flag == 0) {
        pos = lft;
        for (int i = lft; i <= ryt; ++i) {
            if(A[pos] > A[i]) {
                pos = i;
            }
        }
    }
    printf("%d\n",pos);
    if(pos == 0) {
        low = lower_bound(A.begin(),A.end(),B);
        if((low- A.begin()) <= pos-1 && A[low-A.begin()] == B) {
            return low-A.begin();
        }
        return -1;
    }
    low = lower_bound(A.begin(),A.begin() + pos,B);
    if((low- A.begin()) <= pos-1 && A[low-A.begin()] == B) {
        return low-A.begin();
    }
    low = lower_bound(A.begin() + pos,A.end(),B);
    if((low- A.begin()) <= A.size()-1 && A[low-A.begin()] == B) {
        return low-A.begin();
    }
    return -1;
}


// main code begins now

int main()
{
    int k;
    vector<int> v;
    for (int i = 0; i < 5; ++i){
        cin >> k ;
        v.push_back(k);
    }
    cout << search(v,1) << endl;
    return 0;
}
