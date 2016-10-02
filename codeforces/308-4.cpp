#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;


// main code begins now

int main()
{
    // freopen("in.txt", "r", stdin);
	LL n,answer=0,x,y,i,j,k;
	vector<pair<LL,LL> > pnt;
    cin >> n;
    for ( i = 0; i < n; ++i) {
    	scanf("%I64d %I64d",&x,&y);
    	pnt.push_back(make_pair(x,y));
    }
    if(n<3){
    	printf("0\n");
    	return 0;
    }
    for ( i = 0; i < n; ++i) {
    	for ( j = i+1; j < n; ++j) {
    		for ( k = j+1; k < n; ++k) {
    			if( (pnt[j].second-pnt[i].second)*(pnt[k].first-pnt[i].first) != (pnt[k].second-pnt[i].second)*(pnt[j].first-pnt[i].first) ) answer++;
    		}
    	}
    }
    printf("%I64d\n",answer);
    return 0;
}