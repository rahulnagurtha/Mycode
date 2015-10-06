#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int one,two,n,temp,count=0,temp1;
    	vector<pair<int,int> > v;
    	cin >> n ;
    	for (int i = 0; i < n; ++i) {
    		scanf("%d%d",&one,&two);
    		v.push_back(make_pair(one,two));
    	}
    	sort(v.begin(),v.end());
    	for (int i = 0; i < v.size();) {
    		temp=v[i].second;
    		temp1=i+1;
    		while(temp1<v.size()) {
    			if(v[temp1].first <=temp) {
    				i++;
    				temp1++;
    			}
    			else break;
    		}
    		i++;
    		count++;
    	}
    	printf("%d\n",count);
    }
    return 0;
}