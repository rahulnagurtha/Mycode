#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    stack <int> a[4];
    int ans,num[5],temp;
    num[1]=0;
    num[2]=0;
    num[3]=0;
    int n;
    cin >> n ;
    for (int i = 1; i <= n; ++i) {
    	cin >> temp ;
    	num[temp]++;
    	a[temp].push(i);
    }
    ans=min(num[3],min(num[1],num[2]));
    if(ans==0) {
    	printf("0\n");
    	return 0;
    }
    printf("%d\n",ans);
    for (int i = 0; i < ans; ++i) {
    	cout << a[1].top() << " " << a[2].top() << " " << a[3].top() << " " << endl ;
    	a[1].pop();
    	a[2].pop();
    	a[3].pop();
    }
    return 0;
}