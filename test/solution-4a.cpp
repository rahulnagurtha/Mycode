list<pair<int,int> > f(list<int> &X, int l, int r) {
	list<pair<int,int> > ret_list;
	if(l == r) {
		if(X[l] > 0) {
			ret_list.push_back(pair(l,r));
		}
	}
	else {
		int mid = (floor)(l+r)/2;

		list<pair<int,int> > lft_answer = f(X,l,mid);
		list<pair<int,int> > ryt_answer = f(X,mid+1,r);

		if (lft_answer.size() > 0 && ryt_answer.size() 
			&& lft_answer.back().second == mid && ryt_answer.front().first == mid + 1) {
			lft_answer.back().second = ryt_answer.front().second;
			ryt_answer.pop_front();
		}
		ret_list = append(lft_answer,ryt_answer);
	}
	return ret_list;
}

The time complexity of the alogirthm is O(N*logN) because at the merging step we are appending both the lists which makes
the time complexity of merging as O(N).

So the equation for time complexity is T(N) = 2*T(N/2) + O(N). This is equation is same as that of merge sort
and hence the time complexity will come out to be same as that of merge sort which is O(N*logN).