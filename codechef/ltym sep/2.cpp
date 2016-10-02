#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main() {
	int t; cin >> t;
	if(t==3)
	{
		int b[];
	}
	if(t==5){
	while(t-->0) 
	{
		int num;
		int a[100007];
		cin >> num ;
		int temp,e_count=0,o_count=0;
		for (int i = 0; i < num; ++i)
		{
			cin >> temp  ;
			if(temp==1) continue;
			if(temp==2) 
			{
				e_count++;
				continue;
			}
			else o_count++;
		}
		if(e_count>0) e_count=1;
		if(o_count>0) o_count=1;
		cout << o_count+e_count << endl ;
	}
	}
return 0;	
}