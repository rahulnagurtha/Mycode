#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    int t,temp1,temp2,b;
    long long int count=0;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	cin >> b ;
    	//x+y=b
    	for (int i = 2; i <= b; i=i+2) {
    		temp2=b-i;
    		if(temp2>0) {
    			// printf("adding for %d\n",i);
    			count+=(long long int)(temp2/2);
    		}
    		else {
    			// printf("not adding for %d\n",i);
    		}
    	}
    	cout << count << endl ;
    	count=0;
    }
    return 0;
}