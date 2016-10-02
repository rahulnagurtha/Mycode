#include <bits/stdc++.h>

using namespace std;


typedef long long int lint;

	
int main()
{
	int n;
	int x,y,best=2;
	cin >> n ;
	if(n==0)
	{
		cout << "4" ;
		return 0;
	}
	if(n==2)
	{
		cout << "2" ;
		return 0;
	}
	if(n==1)
	{
		cout << "3" ;
		return 0;
	}
	set <pair<int,int> > points;

	vector<pair<int,int> > v;
	v.reserve(2000);

	// taking input
	for (int i = 0; i < n; ++i) {
    	cin >> x >> y ;
		points.insert (make_pair(x,y));
		v.push_back(make_pair(x,y));
	}
	
	
	pair<int,int> one,two,p[4];
	int x1,y1,x2,y2;
	set<pair<int,int> >::iterator it1,it2,it3,it4;
	
	//brute force with each two points
	for (int i = 0; i < v.size()-1; ++i)
	{
		one=v[i];
		x1=v[i].first;
		y1=v[i].second;
		for (int j = i+1; j < v.size(); ++j)
		{
			two=v[j];
			x2=v[j].first;
			y2=v[j].second;
			//finding unique points with two points
			p[0]=make_pair(x1+y1-y2,x2+y1-x1);
			p[1]=make_pair(x2+y1-y2,y2+x2-x1);
			p[2]=make_pair(x1+y2-y1,y1-x2+x1);
			p[3]=make_pair(x2+y2-y1,y2-x2+x1);
			//////////////////////////////////////
			
			//seraching
			it1=points.find(p[0]);
			it2=points.find(p[1]);
			it3=points.find(p[2]);
			it4=points.find(p[3]);
			if( (it1!=points.end() && it2!=points.end()) || (it3!=points.end() && it4!=points.end()) ) best=0;
			else if( (it1!=points.end() || it2!=points.end()) || (it3!=points.end() || it4!=points.end()) )
			{
				if(best>1) best=1;
			}
			else
			{
				if(best>2) best=2; 
			}
		}
	}
	cout << best << endl ;
	//yo rahul,mission accomplished :P
	return 0;
}