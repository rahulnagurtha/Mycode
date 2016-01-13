#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,x;
	double teams;
	std::ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		
		teams=1;
		cin >> n;
		int choice[n+1];
		cin >> x;
		for (int i = 1; i < n; ++i)
		{
			cin >> x;
			if(x==-1)
				teams+=0.5;
		}
		
		cout << teams <<"\n";
	}

	
	return 0;
}