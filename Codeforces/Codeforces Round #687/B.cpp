#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long N, K;
		cin >> N >> K;
		vector<long long> v(N);
		for (auto &i : v)cin >> i;
		int ans = 210000000;
		for (int i = 1; i <= 100; i++) {
			auto temp = v;
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				if (temp[j] != i) {
					for (int k = 0; k < K; k++) {
						if (j + k < N)temp[j + k] = i;
					}
					cnt++;
				}
			}
			ans = min(ans, cnt);
		}
		cout << ans << '\n';
	}
}
