#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long N, k; cin >> N >> k;
		vector<pair<int, int>>v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i].first >> v[i].second;
		}
		bool possible = 0;
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				if (llabs(v[i].first - v[j].first) + llabs(v[i].second - v[j].second) <= k) {
					cnt++;
				}
			}
			if (cnt == N) {
				possible = 1; break;
			}
		}
		cout << (possible ? 1 : -1) << '\n';
	}
}
