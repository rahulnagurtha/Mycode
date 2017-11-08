pair<int,int> f(int *answer, list<int> &X, int l, int r) {
	pair<int,int> ret_pair;
	if(l == r) {
		if(X[l] > 0) {
			ret_pair = pair(0,0);
		}
		else {
			ret_pair = pair(0,0);
			*answer = max(*answer,1);
		}
	}
	else {
		int mid = (floor)(l+r)/2;

		pair<int,int> lft_pair = f(answer,X,l,mid);
		pair<int,int> ryt_pair = f(answer,X,mid+1,r);

		int length_of_longest_crossing_segment = lft_pair.second + ryt_pair.first;

		*answer = max(*answer,length_of_longest_crossing_segment);

		if(lft_pair.first == (mid - l + 1)) {
			ret_pair.first = lft_pair.first + ryt_pair.first;
		}
		else {
			ret_pair.first = lft_pair.first;
		}

		if(ryt_pair.second == (r - mid)) {
			ret_pair.second = lft_pair.second + ryt_pair.second;
		}
		else {
			ret_pair.second = ryt_pair.second;
		}

	}
	return ret_pair;
}

The time complexity of the alogirthm is O(N) because at the merging step we are making only constant number of operations which makes
the time complexity of merging as O(1).

So the equation for time complexity is T(N) = 2*T(N/2) + O(1), we get O(N) as time complexity solving this equation.