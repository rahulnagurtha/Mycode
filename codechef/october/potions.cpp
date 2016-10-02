#include <bits/stdc++.h>


using namespace std;


typedef long long int lint;

	
int main()
{
	int t;
	cin >> t ;
	while(t--) {
		int n,m1,m2,m3;
		cin >> m1 >> m2 >> m3 >> n ; 
		int temp,max=-1,a[4];
		for (int i = 0; i < m1 ; ++i) {
			cin >> temp ;
			if(max<temp) max=temp;
		}
		a[0]=max;
		max=-1;
		for (int i = 0; i < m2 ; ++i) {
			cin >> temp ;
			if(max<temp) max=temp;
		}
		a[1]=max;
		max=-1;
		for (int i = 0; i < m3 ; ++i) {
			cin >> temp ;
			if(max<temp) max=temp;
		}
		a[2]=max;
		sort(a,a+3);
		for (int i = 0; i < n; ++i)
		{
			//cout << "the order is :" << a[0] << " " << a[1] << " " << a[2] << endl ;
			a[2]=a[2]/2;
			sort(a,a+3);
		}
		cout << a[2] << endl ;	
	}
	return 0;
}