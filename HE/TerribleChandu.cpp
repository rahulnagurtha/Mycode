#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--) {
		string tmp;
		cin >> tmp;
		for(int i = tmp.size() - 1; i >= 0 ; i--) {
			cout << tmp[i];
		}
		cout << endl;
	}
    return 0;
}
