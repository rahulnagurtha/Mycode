// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int modX,modY;
    int ans = 0;
    for(int i = 1; i < X.size(); i++) {
        modX = abs(X[i] - X[i-1]);
        modY = abs(Y[i] - Y[i-1]);
        ans += min(modX,modY) + modX - 2*min(modX,modY) + modY;
    }
    return ans;
}