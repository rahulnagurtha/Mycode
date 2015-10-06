#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main() {
	int t; cin >> t;
	while(t-->0) {
		int mice[131080],holes[131080];
		int ans;
		int num;
		cin >> num ;
		for (int i = 0; i < num; ++i)
		{
			cin >> mice[i] ;
		}
		for (int i = 0; i < num; ++i)
		{
			cin >> holes[i] ;
		}
		sort(mice,mice+num);
		sort(holes,holes+num);
		ans=abs(mice[0]-holes[0]);
		for (int i = 0; i < num; ++i)
		{
			if(abs(mice[i]-holes[i])>ans) ans=abs(mice[i]-holes[i]);
		}
		cout << ans << endl ;
	}
return 0;	
}