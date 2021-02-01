#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {
		long long N; cin >> N;
		vector<long long>v(N);
		set<long long>s;
		int ans = 0;
		for (auto &i : v)cin >> i;
		for (int i = 0; i < N; i++) {
			if (s.find(v[i]) == s.end()) {
				s.insert(v[i]);
				ans++;
			}
			else {
				if (s.find(v[i] + 1) == s.end()) {
					s.insert(v[i] + 1);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}
