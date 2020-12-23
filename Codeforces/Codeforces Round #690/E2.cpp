#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long MAX_NUM = 4000001;
long long f[MAX_NUM];
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
void nCrInit() {
	f[0] = 1; f[1] = 1;
	for (int i = 2; i <= MAX_NUM - 1; i++) {
		f[i] = f[i - 1] * i;
		f[i] %= MOD;
	}
}
long long nCr(int n, int r) {
	return (f[n] * mypow((f[r] * f[n - r]) % MOD, MOD - 2, MOD)) % MOD;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	nCrInit();
	int T; cin >> T;
	while (T--) {
		int N, M, K; cin >> N >> M >> K;
		long long ans = 0;
		vector<long long>v(N);
		for (auto &i : v)cin >> i;
		sort(v.begin(), v.end());
		for (int i = 0; i < N; i++) {
			auto it = upper_bound(v.begin(), v.end(), K + v[i]) - v.begin();
			if (it - i - 1 >= M - 1)ans += nCr(it - i - 1, M - 1);
			ans %= MOD;
		}
		cout << ans << '\n';
	}
}
