bool cmp(pair<int,int> lft,pair<int,int> ryt) {
	if(lft.first == ryt.first) return lft.second < ryt.second;
	return lft.first > ryt.first;
}

vector<int> Solution::flip(string A) {
	deque<pair<int,int> > Q;
	vector<int> range;
	int profit = 0;
	int ans = 0;
	for(int i = 0 ;i < A.size();i++) {
		if(A[i] == '0') {
			profit++;
		}
		else {
			profit--;
		}
		Q.push_back(make_pair(profit,i));
	}
	sort(Q.begin(),Q.end(),cmp);
	int toRemove = 0;
	int L = -1,R = -1;
	for(int i = 0; i < A.size();i++) {
		while(!Q.empty() && Q.front().second < i) Q.pop_front();
		if(ans < (Q.front().first - toRemove)) {
			ans = Q.front().first - toRemove;
			L = i;
			R = Q.front().second;
		}
		if(A[i] == '0') toRemove++;
		else toRemove--;
	}
	if(L == -1) return range;
	range.push_back(L+1);
	range.push_back(R+1);
	return range;
}