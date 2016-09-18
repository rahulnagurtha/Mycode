#define MOD 1000000007

int Solution::cntBits(vector<int> &A) {
	int ans = 0;
	int zero[32] = {0};
	int one[32] = {0};
	for (int i = 0; i < A.size(); ++i) {
		int tmp = A[i];
		for (int j = 0; j < 32; ++j) {
			if(tmp%2 == 0) zero[j]++;
			else one[j]++;
			tmp = tmp/2;
		}
	}
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < 32; ++j) {
			//bit is 1
			if(A[i] & (1 << j)) {
				ans += zero[j];
			}
			else {
				ans += one[j];
			}
			ans %= MOD;
		}
	}
	return ans%MOD;
}