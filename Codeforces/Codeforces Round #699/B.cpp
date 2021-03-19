#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int T; cin >> T; while(T--) {

		ll N, K; cin >> N >> K;
		vector<ll> v(N);
		for (auto &i : v)cin >> i;

		ll ans = -1;

		for (int i = 0; i < K; i++) {
			ll t = 0;
			for (int j = 0; j < N; j++) {
				if (j == N - 1) {
					t = 1;
					break;
				}
				if (v[j] < v[j + 1]) {
					v[j]++;
					if (i == K - 1)ans = j;
					break;
				}
			}
			if (t)break;
		}
		cout << (ans == -1 ? ans : ans + 1) << '\n';
	}
}
