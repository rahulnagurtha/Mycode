typedef long long int ll;

bool Solution::isPower(int A) {
    if(A == 1) return true;
	ll tmp;
	ll target = (ll)A;
	for (ll i = 2; i <= 65536; ++i) {
		tmp = i*i;
		while(tmp <= target) {
			if(tmp == target) return true;
			tmp = tmp*i;
		}
	}
	return false;
}