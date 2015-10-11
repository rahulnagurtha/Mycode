#include <bits/stdc++.h>

using namespace std;





int main()
{
	int a =1;

    int n;
    char other,x;
    string paper[303];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
		cin >> paper[i];
    }
    x = paper[0][0];
    other = paper[0][1];
    if(x == other) {
    	printf("NO\n");
    	return 0;
    }
    // assert(a == 0);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		if(i == j || i+j == n-1) {
    			if(paper[i][j] != x) {
    				printf("NO\n");
    				return 0;
    			}
    		}
    		else {
    			if(paper[i][j] != other) {
    				printf("NO\n");
    				return 0;
    			}
    		}
    	}
    }
    printf("YES\n");
    return 0;
}