#include <bits/stdc++.h>

using namespace std;


typedef long long int LL;


// main code begins now

int main()
{
    LL n,val,lft = -99999999999,ryt = 999999999999,flag=0;
    string ans,symbol;
    cin >> n ;
    for (int i = 0; i < n; ++i) {
    	cin >> symbol >> val >> ans ;
    	if(flag == 1) continue;
    	if( symbol == "<") {
	    	if (ans == "Y") {
	    		if(val-1 < ryt) ryt = val - 1;
	    	}
	    	else {
	    		if(val > lft) lft = val;
	    	}
	    }
	    else if( symbol == ">") {
	    	if (ans == "Y") {
	    		if(val+1 > lft) lft = val + 1;
	    	}
	    	else {
	    		if(val < ryt) ryt = val;
	    	}
	    }
	    else if( symbol == "<=") {
	    	if (ans == "Y") {
	    		if(val < ryt) ryt = val;
	    	}
	    	else {
	    		if(val+1 > lft) lft = val + 1;
	    	}
	    }
	    else {
	    	if (ans == "Y") {
	    		if(val > lft) lft = val;
	    	}
	    	else {
	    		if(val-1 < ryt) ryt = val - 1;
	    	}
	    }
	    if(lft > ryt) flag = 1;
    }
    if(flag == 1) printf("Impossible\n");
    else {
    	if(lft < -2000000000) printf("-2000000000\n");
    	else if(lft > 2000000000) printf("2000000000\n");
    	else printf("%I64d\n",lft);
    }
    return 0;
}