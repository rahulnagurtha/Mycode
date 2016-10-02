#include <bits/stdc++.h>
 
using namespace std;
 
 
 
// main code begins now
 
int main() {

    bool status[105][105];
    int n,m,k,row,column,flag,count=0,count1=0;
    vector<pair<int,int> > a,b;
    a.reserve(10000);
    b.reserve(10000);
    int array[105];
    memset(array,0,105);
    //input
    cin >> n >> m >> k ;
    for (int i = 0; i < k; ++i) {
        cin >> row >> column ;
        status[row][column]=true;
    }

 
    //column wise
    for (int i = 1; i <=m ; ++i) {
        flag=1;
        for (int j = 1; j <= n; ++j) {
            if(status[j][i]==false && flag==1) {
                a.push_back(make_pair(j,i));
                status[j][i]=true;
                count++;
                flag=0;
            }
            if(status[j][i]==false && flag==0) {
                status[j][i]=true;
            }
            if(status[j][i] == true) {
                flag=1;
            }
        }
    }
    /*
    //row wise
    for (int i = 1; i <=n ; ++i) {
        flag=1;
        for (int j = 1; j <= m; ++j) {
            if(status[i][j]==false && flag==1) {
                b.push_back(make_pair(i,j));

                count1++;
                flag=0;
            }
            if(status[i][j] == true) {
                flag=1;
            }
        }
    }
*/
    printf("\nprinting status:\n");
    for (int i = 1; i <=n; ++i)
    {
        for (int j = 1; j <=m; ++j)
        {
            cout << status[i][j] << " " ;
        }
        printf("\n");
    }
    //if(count < count1) {
        cout << count << endl ;
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i].first << " " << a[i].second << " " << "1" << endl ;
        //}
    }
  /*  else {
        cout << count1 << endl ;
        for (int i = 0; i < b.size(); ++i) {
            cout << b[i].first << " " << b[i].second << " " << "0" << endl ;
        }
    }*/
    return 0;
}