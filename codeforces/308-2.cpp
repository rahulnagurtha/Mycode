#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n,store,totaldigits,answer;
LL one,two;

// main code begins now

int main()
{
	one = 9;
	two = 1;
    cin >> n;
    store = n;
	while(n != 0) {
		n = n/10;
		totaldigits++;
	}
	for (LL i = 1; i < totaldigits; ++i) {
		answer += i*(one-two+1);
		one = one*10+9;
		two = two*10;
	}
	answer += totaldigits*(store-two+1);
	cout << answer;
    return 0;
}