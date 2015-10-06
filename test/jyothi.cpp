#include <bits/stdc++.h>

using namespace std;



int task(int a,int m) {
	for (int i = 0; i < m ; ++i) {
		if((a*i)%m == 1) return i;
	}
}

// main code begins now

int main()
{
    int a,b,c;
    cin >> a >> b ;
    cout << task(a,b) << endl ;
    return 0;
} 