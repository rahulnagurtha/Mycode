#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    int n,m,k,temp1,temp2,flag=0,check;
    set<pair<int,int> > steps;
    // set<pair<int,int> >::iterator it;
    // freopen("in.txt", "r", stdin);
    cin >> n >> m >> k ;
    for (int i = 0; i < k; ++i) {
    	cin >> temp1 >> temp2 ;
    	check=0;
    	if(steps.find(make_pair(temp1,temp2+1)) != steps.end() && steps.find(make_pair(temp1+1,temp2)) != steps.end() && steps.find(make_pair(temp1+1,temp2+1)) != steps.end() ) {
    		check++;
    	}
    	if(steps.find(make_pair(temp1,temp2-1)) != steps.end() && steps.find(make_pair(temp1-1,temp2-1)) != steps.end() && steps.find(make_pair(temp1-1,temp2)) != steps.end() ) {
    		check++;
    	}
    	if(steps.find(make_pair(temp1,temp2+1)) != steps.end() && steps.find(make_pair(temp1-1,temp2)) != steps.end() && steps.find(make_pair(temp1-1,temp2+1)) != steps.end() ) {
    		check++;
    	}
    	if(steps.find(make_pair(temp1,temp2-1)) != steps.end() && steps.find(make_pair(temp1+1,temp2)) != steps.end() && steps.find(make_pair(temp1+1,temp2-1)) != steps.end() ) {
    		check++;
    	}
    	if(check>0) {
    		printf("%d\n",i+1);
    		flag=1;
    		break;
    	}
    	else steps.insert(make_pair(temp1,temp2));
    }
    if(flag==0) {
    		printf("0\n");
    	}
    return 0;
}