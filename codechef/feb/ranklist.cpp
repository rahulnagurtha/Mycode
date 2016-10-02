#include <bits/stdc++.h>

using namespace std;



// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	long long int n,s,count=0,tbadd;
    	cin >> n >> s ;
    	s=s-n;
    	tbadd=0;
    	for (int i = 1; i <= n; ++i) {
    		// printf("to be added is %d\n",tbadd);
    		if(s>=tbadd) {
    			count++;
    			s=s-tbadd;
    			tbadd++;
    		}
    		else {
    			break;
    		}
    	}
    	tbadd=n-count;
    	cout << tbadd << endl ;

    }
    return 0;
}