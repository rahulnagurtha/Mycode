#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int count[30],temp,sum=0,flag=0;
    	memset(count,0,sizeof(count));
    	string a;
    	cin >> a ;
    	for (int i = 0; i < a.size(); ++i) {
    		temp=(int)(a[i])-97;
    		count[temp]++;
    	}
    	for (int i = 0; i < 26; ++i) {
    		sum+=count[i];
    	}
    	for (int i = 0; i < 26; ++i) {
    		if(2*count[i] == sum) {
    			flag=1;
    		}
    	}
    	if (flag==1)
    	{
    		printf("YES\n");
    	}
    	else {
    		printf("NO\n");
    	}
    }
    return 0;
}