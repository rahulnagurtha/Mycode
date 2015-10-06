#include <stdio.h>
#include <iostream>

using namespace std;


int arr[100005],n,lft = 0,ryt,mid,target,pos,res;


int lower_Bound() {
	while(lft <= ryt) {
		if(lft == ryt) {
			if(arr[lft] >= target) return lft+1;
			return -1;
		}
		else {
			mid = (lft + ryt)/2;
			if(arr[mid] >= target) ryt = mid;
			else lft = mid+1;
		}
	}
}


int main()
{
	cin >> n;
	ryt = n-1;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cin >> target;
	res = lower_Bound(); 
	if(res > 0) printf("val found at %d\n",res);
	else printf("no lower bound found\n");
	return 0;
}