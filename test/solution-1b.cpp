int get_max_peak_position(list<int> &X,int i,int j) {
	if(i > 0 && j > 0) {
		if(X[i] > X[j]) return i;
		else return j;
	}
	else if(i > 0) {
		return i;
	}
	else if(j > 0) {
		return j;
	}
	else {
		return -1;
	}
}

int f(list<int> &X, int l, int r) {
	int position_of_highest_peak_in_current_segment = -1;

	if(r - l > 2) {
		int mid = (floor)(l+r)/2;

		int position_of_highest_peak_in_lft_segment = f(X,l,mid);
		int position_of_highest_peak_in_ryt_segment = f(X,mid+1,r);
		int number_of_elements_in_lft_segment = mid - l + 1;
		int number_of_elements_in_ryt_segment = r - mid;
		
		position_of_highest_peak_in_current_segment = get_max_peak_position(position_of_highest_peak_in_current_segment,position_of_highest_peak_in_lft_segment);
		position_of_highest_peak_in_current_segment = get_max_peak_position(position_of_highest_peak_in_current_segment,position_of_highest_peak_in_ryt_segment);
		
		if ((number_of_elements_in_lft_segment > 1) && (X[mid - 1] < X[mid]) && (X[mid] > X[mid+1])) {
			position_of_highest_peak_in_current_segment = get_max_peak_position(position_of_highest_peak_in_current_segment,mid);
		}


		if ((number_of_elements_in_ryt_segment > 1) && (X[mid] < X[mid + 1]) && (X[mid + 1] > X[mid + 2])) {
			position_of_highest_peak_in_current_segment = get_max_peak_position(position_of_highest_peak_in_current_segment,mid + 1);
		}
	}
	return position_of_highest_peak_in_current_segment;
}

The time complexity of the alogirthm is O(N) because at the merging step we are making only constant number of operations which makes
the time complexity of merging as O(1).

So the equation for time complexity is T(N) = 2*T(N/2) + O(1), we get O(N) as time complexity solving this equation.