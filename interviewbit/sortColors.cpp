void Solution::sortColors(vector<int> &A) {
    int onePtr = 0;
    int twoPtr = A.size()-1;
    for (int i = 0; i <= twoPtr; ++i) {
        if(A[i] == 0) {
            swap(A[onePtr],A[i]);
            onePtr++;
        }
        else if(A[i] == 2) {
            swap(A[i],A[twoPtr]);
            if(i == twoPtr) break;
            twoPtr--;
            i--;
        }
    }
    return; 
}