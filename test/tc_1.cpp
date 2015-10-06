#include <bits/stdc++.h>

using namespace std;


int task(int req,int wvhave,int sum) {
	if(wvhave<=req) {
		return (sum+1);
	}
	else {
		sum+=((wvhave%2==0)?( 2*task(req,wvhave/2,sum) ):( task(req,(wvhave-1)/2,sum) + task(req,(wvhave+1)/2,sum) ));
		return sum;
	}
}


// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int size,crates,sum=0;
    	cin >> size >> crates ;
    	cout << task(size,crates,sum) << endl ;
    	printf("%d\n", 1 << 4 );
    }
    return 0;
}