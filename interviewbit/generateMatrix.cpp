vector<vector<int> > Solution::generateMatrix(int A) {
    int n = A;
    int nxt = 1;
    string direction = "right";
    int x1 = -1,x2 = n;
    int y1 = -1,y2 = n;
    vector<vector<int> > ans;
    vector<int> tmp(A);
    for(int i = 0; i < n;i++) {
        ans.push_back(tmp);
    }

    while(nxt <= A*A) {
        if(direction == "right") {
            x1++;x2--;
            y1++;y2--;
            if(x1 == x2) {
                ans[x1][y1] = nxt;
                break;
            }
            for(int i = y1;i < y2;i++) {
                ans[x1][i] = nxt;
                nxt++;
            }
            direction = "down"; 
        }
        else if(direction == "down") {
            for(int i = x1;i < x2;i++) {
                ans[i][y2] = nxt;
                nxt++;
            }
            direction = "left";
        }
        else if(direction == "left") {
            for(int i = y2;i > y1;i--) {
                ans[x2][i] = nxt;
                nxt++;
            }
            direction = "up";
        }
        else {
            for(int i = x2;i > x1;i--) {
                ans[i][y1] = nxt;
                nxt++;
            }
            direction = "right";
        }
    }
    return ans;
}