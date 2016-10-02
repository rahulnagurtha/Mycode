#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

	
int main()
{
	int test;
	cin >> test ;
	while(test--) {
		lint cost=0;
		int n;
		cin >> n ;
		int p1,p2,temp,v_count,d_count;
		vector<pair<int,int> > villagers;
		vector<pair<int,int> > dino ;
		villagers.reserve(1000);
		dino.reserve(1000);
		villagers.push_back(make_pair(0,0));
		dino.push_back(make_pair(0,0));
		for (int i = 1; i <= n; ++i)
		{
			cin >> temp ;
			if(temp>=0) villagers.push_back(make_pair(i,temp));
			else dino.push_back(make_pair(i,-temp));
		}
		v_count=villagers.size()-1;
		d_count=dino.size()-1;
		p1=1,p2=1;

		/*for (int i = 1; i < v_count; ++i)
		{
			cout << villagers[i].first << villagers[i].second << endl ;
		}*/


		while(v_count>0) {
			if(villagers[p1].second > dino[p2].second) {
				cost+=(abs(villagers[p1].first-dino[p2].first))*dino[p2].second;
				villagers[p1].second-=dino[p2].second;
				p2++;
				continue;
			}
			else if(villagers[p1].second < dino[p2].second) {
				cost+=(abs(villagers[p1].first-dino[p2].first))*villagers[p1].second;
				dino[p2].second-=villagers[p1].second;
				p1++;
				v_count--;
				continue;
			}
			else {
				cost+=(abs(villagers[p1].first-dino[p2].first))*villagers[p1].second;
				p1++;
				p2++;	
				v_count--;		
			}
		}
		cout << cost << endl ;
	}
	return 0;
}