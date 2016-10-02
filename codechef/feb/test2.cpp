#include <bits/stdc++.h>

using namespace std;



// main code begins now

int main()
{
    int t1,t2;
    vector<pair<int,int> >edges(5);
    for (int i = 0; i < 5; ++i) {
    	cin >> t1 >> t2 ;
    	edges[i]=make_pair(t1,t2);
    }
	
    for (int i = 0; i < 5; ++i) {
    	cout << edges[i].first << " " << edges[i].second ;
    	printf("\n");
    	// edges[i]=make_pair(t1,t2);
    }
    return 0;
}