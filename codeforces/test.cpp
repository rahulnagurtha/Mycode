#include <bits/stdc++.h>

using namespace std;

int cnt;

void recurse() {
	cnt++;
	printf("%d\n",cnt);
	recurse();
}


// main code begins now

int main()
{
	cnt = 0;
    recurse();
    return 0;
}