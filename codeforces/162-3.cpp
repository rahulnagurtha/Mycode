#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{
	deque<int> left,right;
	int tmp;
    string inp;
    cin >> inp ;
    for (int i = 0; i < inp.size(); ++i) {
		if(inp[i] == 'l') {
			right.push_front(i+1);
		}
		else {
			left.push_back(i+1);
		}
    }
    for (int i = 0; i < left.size(); ++i) {
    	printf("%d\n",left[i]);
    }
    for (int i = 0; i < right.size(); ++i) {
    	printf("%d\n",right[i]);
    }
    return 0;
}