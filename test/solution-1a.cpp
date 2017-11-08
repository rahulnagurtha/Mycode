list<int> f(list<int> &X, int l, int r) {
	list<int> ret_list;
	if(r - l > 2) {
		int mid = (floor)(l+r)/2;

		list<int> lft_answer = f(X,l,mid);
		list<int> ryt_answer = f(X,mid+1,r);
		int number_of_elements_in_lft_segment = mid - l + 1;
		int number_of_elements_in_ryt_segment = r - mid;
		
		if ((number_of_elements_in_lft_segment > 1) && (X[mid - 1] < X[mid]) && (X[mid] > X[mid+1])) {
			lft_answer.push_back(mid);
		}

		if ((number_of_elements_in_ryt_segment > 1) && (X[mid] < X[mid + 1]) && (X[mid + 1] > X[mid + 2])) {
			ryt_answer.push_back(mid + 1);
		}

		ret_list = append(lft_answer,ryt_answer);
	}
	return ret_list;
}

The time complexity of the alogirthm is O(N) because at the merging step we are making only constant number of operations which makes
the time complexity of merging as O(1).

So the equation for time complexity is T(N) = 2*T(N/2) + O(1), we get O(N) as time complexity solving this equation.