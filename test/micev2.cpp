#include <bits/stdc++.h>

using namespace std;


int main() {

	int t;
	 cin >> t;
	 while(t-->0) {
	 	//take input
	 	int n,m,i,j,k,mice[200007],holes[200007];
	 	cin >> n >> m;
	 	for(i=0;i<n;i++) {
	 		cin >> mice[i];
	 	}
	 	for(i=0;i<m;i++) {
	 		cin >> holes[i];
	 	}
	 	sort(mice,mice+n);
		sort(holes,holes+m);
	 	//process
	 	int left=0;
	 	j=0;
	 	int right = m-n+1;
	 	int final_res = 0;
	 	for(i=0;i<n;i++) {
	 		int min_here = 1000000009;
	 		int min_pos;
	 		for(j=left;j<=right;j++) {
	 			min_here = min(min_here,abs(holes[j]-mice[i]));
	 		}
	 		for(j=left;j<=right;j++) {
	 			if(abs(holes[j]-mice[i])==min_here) {
	 				min_pos = j;
	 				break;
	 			}
	 		}
	 		left = min_pos + 1;
	 		right++;

	 		final_res = max(final_res, min_here);

		}
	 	cout << final_res << "\n";
	 }


	return 0;
}