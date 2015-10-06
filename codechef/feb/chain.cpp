#include <bits/stdc++.h>

using namespace std;

// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	getchar();
    	string a;
    	char test[3];
    	int temp,first=0,second=0,ans;
    	cin >> a ;
    	test[0]='+';
    	test[1]='-';
    	temp=0;
    	for (int i = 0; i < a.size(); ++i) {
    		if(a[i]!=test[temp]) {
    			first++;
    		}
    		temp++;
    		temp=temp%2;
    	}
    	temp=1;
    	for (int i = 0; i < a.size(); ++i) {
    		if(a[i]!=test[temp]) {
    			second++;
    		}
    		temp++;
    		temp=temp%2;
    	}
    	ans=min(first,second);
    	cout << ans << endl ;

    }
    return 0;
}