#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main() {
	int t; cin >> t;
	while(t-->0) 
	{
		lint sum=0;
		int pile[100007];
		int num;
		cin >> num ;
		for (int i = 0; i < num; ++i)
		{
			cin >> pile[i] ;
		}	
		sort(pile,pile+num);
		for (int i = num-1; i >=0; i-=2)
		{
			sum+=pile[i];
		}
		cout << sum << endl ;
	}
	
return 0;	
}