#include <bits/stdc++.h>
using namespace std;
 
vector< int > games(100, -1);
// can player 1 win
bool canWin(int N) {
	if(games[N]!=-1) return games[N];
	games[N] = 0;
	for (int i = 1; i <= N; ++i)
	{
		if(canWin(max(0, i-2)) ^ canWin(max(0, N - i -3)) == 0) games[N] = 1;
	}
	return games[N];
}
 
int main() {
	int n;
	games[0] = 0;
	games[1] = games[2] = 1;
	canWin(50);
	for (int i = 0; i < 50; ++i)
	{
		cout << i << " " << games[i] << endl;
	}
}