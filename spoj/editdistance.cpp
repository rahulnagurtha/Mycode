#include <bits/stdc++.h>

using namespace std;


int arr[2001][2001];

// main code begins now

int main()
{
    int t;
    cin >> t ;
    while(t--) {
        memset(arr,0,2001*2001);
        int len1,len2;
        string a,b,temp1,temp2;
        a="t";
        b="t";
        cin >> temp1 >> temp2 ;
        a+=temp1;
        b+=temp2;
        len1=a.size()-1;
        len2=b.size()-1;
        //cout << a << " " << b << endl ;
        for (int i = 0; i <= len1; ++i) {
            arr[0][i]=i;
        }
        for (int i = 0; i <= len2; ++i) {
            arr[i][0]=i;
        }
        for (int j = 1; j <=len2 ; ++j) {
            for (int i = 1; i <=len1 ; ++i) {  
                if(a[i]==b[j]) arr[i][j]=arr[i-1][j-1];
                else{
                    //cout << a[i] << "!=" << b[i] ;
                    arr[i][j]=min( arr[i-1][j-1]+1, min(arr[i-1][j]+1,arr[i][j-1]+1) );
                    //cout << "  so min of" << arr[i-1][j-1]+2 << "," << arr[i-1][j] +1 << "," << arr[i][j-1]+1 << " is " << arr[i][j] << endl ;
                }
            }
        }
        cout << arr[len1][len2] << endl ;
    }
    return 0;
}
