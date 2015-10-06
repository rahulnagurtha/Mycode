#include <bits/stdc++.h>

using namespace std;

int n,maxdigit,totaldigits,flag;
deque<int> digits;

bool out[10][10];

// main code begins now

int main()
{
	maxdigit = 0;
	cin >> n;
	while(n != 0) {
		digits.push_front(n % 10);
		if(n % 10 > maxdigit) maxdigit = n % 10;
		n = n/10;
		totaldigits++;
	}
	for (int i = 0; i < totaldigits; ++i) {
		for (int j = 0; j < digits.front(); ++j) {
			out[j][i] = true;
		}
		digits.pop_front();
	}
	printf("%d\n",maxdigit);
	for (int i = 0; i < maxdigit; ++i) {
		flag = 0;
		for (int j = 0; j < totaldigits; ++j) {
			if(out[i][j] == true) {
				flag = 1;
				printf("1");
			}
			else {
				if(flag == 1) printf("0");
			}
		}
		printf(" ");
	}
    return 0;
}