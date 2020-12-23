#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, M, K; cin >> N; M = 3, K = 2;
		long long ans = 0;
		vector<long long>v(N);
		for (auto &i : v)cin >> i;
		sort(v.begin(), v.end());
		for (long long i = 0; i < N; i++) {
			auto it = upper_bound(v.begin(), v.end(), v[i] + 2) - v.begin();
			if (it - i >= 2)ans += (it - i - 1)*(it - i - 2) / 2;
		}
		cout << ans << '\n';
	}
}
