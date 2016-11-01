#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ":\n";
		double d;
		int n,a;
		cin >> d >> n >> a;
		vector<double> tim, pos;
		for(int i = 0; i < n; i++) {
			double ti, xi;
			cin >> ti >> xi;
			tim.push_back(ti);
			pos.push_back(xi);
		}
		vector<double> grav;
		for(int i = 0; i < a; i++) {
			double gravi;
			cin >> gravi;
			grav.push_back(gravi);
		}

		for(int k = 0; k < a; k++) {
			double x = 0;
			double u = 0;
			double xo = pos[0];
			double ans = -1;
			for(int i = 1; i < tim.size(); i++) {
				double vo = (pos[i]-pos[i-1])/(tim[i] - tim[i-1]);
				xo = vo * (tim[i] - tim[i-1]);
				double deltat = tim[i] - tim[i-1];
				double acc = (2*(xo - x - u*deltat))/(deltat*deltat);
				acc = min(acc, grav[k]);

				double xnext = x + u*deltat + 0.5*acc*deltat*deltat;
				if(xnext >= d) {
					double extrat = (sqrt(u*u-2*acc*(x-d)) - u)/acc;
					ans = tim[i-1] + extrat;
					break;
				}

				x = xnext;
				u = u + acc*deltat;

			}
			if(ans == -1) {
				double acc = grav[k];
				double extrat = (sqrt(u*u-2*acc*(x-d)) - u)/acc;
				ans = tim[tim.size() - 1] + extrat;
			}
			cout.precision(10);
			cout << ans << "\n"; 


		}

	}



	return 0;
}