#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main() 
{
	while(1) 
	{
		vector< pair<int,int> > v;
		v.push_back(make_pair(-999,-999));
		v.reserve(128);
		int budget,parties,fun,cost;
		cin >> budget >> parties ;
		if(budget==0 && parties==0) break;
		for (int i = 0; i < parties; ++i)
		{
			cin >> cost >> fun ;
			v.push_back(make_pair(cost, fun));
		}
		int a[105][505];
		/*for (int i = 0; i <= 505; ++i)
		{
			a[0][i]=0;
		}*/
		memset(a[0],0,sizeof(a[0]));
		for (int i = 1; i <= parties; ++i)
		{
			for (int j = 0; j <= budget; ++j)
			{
				if(j>=v[i].first) a[i][j]=max((v[i].second+a[i-1][j-v[i].first]),a[i-1][j]);
				else a[i][j]=a[i-1][j];
			}
		}
		int count=0;

		int var1=parties,var2=budget;
		for (int i = 0; i < parties; ++i)
		{
			
			if((var2 >= v[var1].first) && (v[var1].second+a[var1-1][var2-v[var1].first])>a[var1-1][var2])
			{
				count+=v[var1].first;
				var1=var1-1;
				var2=var2-v[var1].first;
				if(var2<=0) break;
			}
			
			else
			{
				var1=var1-1;
				var2=var2;
			}
		}


		cout << count << " " << a[parties][budget] << endl ;
	}
	return 0;	
}