#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long N, sum; cin >> N;
		vector<long long>v(N), psum(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			if (i == 0)psum[i] = v[i];
			else psum[i] = psum[i - 1] + v[i];
		}
		long long ans = N - 1;
		for (int i = 0; i < N; i++) {
			long long aim = psum[i];
			long long cnt = 1, cur = 0;
			bool pos = 1;
			for (int j = i + 1; j < N; j++) {
				cur += v[j];
				if (cur == aim) {
					cur = 0; cnt++;
				}
				else if (cur > aim)pos = 0;
			}
			if (cur == 0 && pos == 1) {
				ans = min(ans, N - cnt);
			}
		}
		cout << ans << '\n';
	}
}
