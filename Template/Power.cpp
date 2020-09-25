long long mypow(long long base, long long exp, long long MOD) {
	long long ans = 1;
	while (exp > 0) {
		if (exp % 2 != 0) {
			ans *= base;
			ans %= MOD;
		}
		base *= base;
		base %= MOD;
		exp /= 2;
	}
	return ans;
}
