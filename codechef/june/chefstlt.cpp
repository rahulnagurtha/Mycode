#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	string one,two;
    	int extra = 0,ans = 0;
    	cin >> one;
    	cin >> two;
    	for (int i = 0; i < one.size(); ++i) {
    		if( one[i] == '?' || two[i] == '?' ) {
    			extra++;
    		}
    		else if(one[i] != two[i]){
    			ans++;
    		}
    		else {
    			i = i;
    		}
    	}
    	// getchar();
    	printf("%d %d\n",ans,ans+extra);
    }
    return 0;
}