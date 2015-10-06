#include <bits/stdc++.h>

using namespace std;

int count_bits(int n) {
	int res= 0;
	while(n>0) {
		if(n%2==1) res++;
		n /= 2;
	}

	return res;
}

int main() {
	int n,i; cin >> n;
	int a[10007];
	for(i=0;i<n;i++) {
		cin >> a[i];
		a[i] = count_bits(a[i]);
	} 
	int res = a[0];
	for(i=1;i<n;i++) {
		res ^= a[i];
	}
	if(res!=0) cout << "Shaka :)\n";
	else cout << "The other player :(\n";
return 0;	
}