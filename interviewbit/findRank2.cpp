#define MOD 1000003LL
typedef long long int ll;

ll fact[1000005];

ll fast_exp(ll a,ll b,ll m) {
	ll ret = 1;
	while(b) {
		if(b&1) ret = (ret*a)%m;
		a = (a*a)%m;
		b = b/2;
	}
	return ret%m;
}

bool isValidToSwap(char lft,char ryt) {
	return lft < ryt;
}

int Solution::findRank(string A) {
	ll ans = 1;
	fact[0] = 0;
	fact[1] = 1;
	for (ll i = 2; i < 1000005; ++i) {
		fact[i] = (fact[i-1]*i) % MOD;
	}
	map<char,ll> cnt;
	for (int j = 0; j < A.size(); ++j) {
		cnt[A[j]]++;
	}
	for (int i = 0; i < A.size(); ++i) {
		cnt[A[i]]--;
		for (int j = 0; j < 26; ++j) {

			if(isValidToSwap(char('a'+j),A[i]) && cnt['a'+ j] != 0) {
				cnt['a'+ j]--;
				cnt[A[i]]++;

				ll tmp = 1;
				for (int k = 0; k < 26; ++k) {
					if(cnt['a'+ k] != 0) tmp = (tmp*fast_exp(fact[cnt['a'+ k]],MOD-2,MOD)) % MOD;
					if(cnt['A'+ k] != 0) tmp = (tmp*fast_exp(fact[cnt['A'+ k]],MOD-2,MOD)) % MOD;
				}
				
				cnt[A[i]]--;
				cnt['a'+ j]++;
				ans = (ans + tmp*fact[A.size() - i - 1]) % MOD;
			}

			if(isValidToSwap(char('A' + j),A[i]) && cnt['A'+ j] != 0) {
				cnt['A'+ j]--;
				cnt[A[i]]++;

				ll tmp = 1;
				for (int k = 0; k < 26; ++k) {
					if(cnt['a'+ k] != 0) tmp = (tmp*fast_exp(fact[cnt['a'+ k]],MOD-2,MOD)) % MOD;
					if(cnt['A'+ k] != 0) tmp = (tmp*fast_exp(fact[cnt['A'+ k]],MOD-2,MOD)) % MOD;
				}
				
				cnt[A[i]]--;
				cnt['A'+ j]++;
				ans = (ans + tmp*fact[A.size() - i - 1]) % MOD;
			}

		}
	}
	return (int)((ans)% MOD);
}