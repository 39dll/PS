#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {

		int N; cin >> N;
		map<long long, int> m;
		vector<long long> v(N);
		for (int i = 0; i < N; i++) {
			int in; cin >> in;
			v[i] = in;
			m[in]++;
		}
		int ans = 0;
		int ind = 0;
		for (auto &i : m) {
			ind++;
			if (i.second == 1) {
				ans = i.first;
				break;
			}
		}
		if (ans == 0)cout << -1 << '\n';
		else {
			for (int i = 0; i < N; i++) {
				if (v[i] == ans) {
					cout << i + 1 << '\n';
					break;
				}
			}
		}
	}
}
