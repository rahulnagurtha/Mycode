#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main() {
	int t; cin >> t;
	while(t-->0) {
		string inp;
		cin >> inp;
		if(next_permutation(inp.begin(), inp.end())) {
			cout << inp << "\n";
		}
		else {
			cout << "no answer\n"; 
		}
	}
return 0;	
}