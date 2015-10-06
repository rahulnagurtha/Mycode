#include <bits/stdc++.h>

using namespace std;






// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	// getchar();
    	int a[3][27]={0},k,flag=0;
    	string one,two;
		cin >> one ;
		cin >> two ;
		for (int i = 0; i < one.size(); ++i) {
			a[0][one[i]-'a']++;
		}
		for (int i = 0; i < two.size(); ++i) {
			a[1][two[i]-'a']++;
		}
		for (int i = 0; i < 26; ++i) {
			if(a[0][i]!=a[1][i]) {
				printf("NO\n");
				flag=1;
				break;
			}
		}
		if (flag==0) {
			printf("YES\n");
		}
    }
    return 0;
}