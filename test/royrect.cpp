#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main() {
	int t; cin >> t;
	while(t-->0) {
		lint x,y,x1,y1,x2,y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		cout << min(abs(y-y2),min(abs(y-y1),min(abs(x-x1),abs(x-x2)))) << "\n";
	}
return 0;	
}