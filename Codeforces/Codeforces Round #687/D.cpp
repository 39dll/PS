#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	long long N; cin >> N;
	vector<long long>v(N), pw2(33);
	long long k = 1;
	for (int i = 0; i < 32; i++) {
		pw2[i] = k; k <<= 1;
	}
	for (auto &i : v)cin >> i;
	auto fd = [&](long long val)->long long {
		for (int i = 31; i >= 0; i--) {
			if (val >= pw2[i]) {
				return i;
			}
		}
	};

	long long prev = fd(v[1]);
	long long prev2 = fd(v[0]);
	for (int i = 2; i < N; i++) {
		long long cur = fd(v[i]);
		if (prev == prev2 && prev == cur) {
			cout << 1;
			return 0;
		}
		prev2 = prev;
		prev = cur;
	}

	long long ans = 2100000000;
	for (int i = 0; i < N; i++) {
		long long one = v[i];
		for (int j = i; j < N; j++) {
			for (int p = i + 1; p <= j; p++) {
				one ^= v[p];
			}
			for (int k = j + 1; k < N; k++) {
				long long two = v[k];
				for (int p = k - 1; p >= j + 1; p--) {
					two ^= v[p];
				}
				if (one > two) {
					ans = min(ans, (long long)k - i - 1);
				}
			}
		}
	}
	cout << (ans == 2100000000 ? -1 : ans);
}
