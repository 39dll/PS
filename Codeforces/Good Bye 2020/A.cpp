#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {
		long long N; cin >> N;
		vector<long long>v(N);
		for (auto &i : v)cin >> i;
		set<long long>s;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (s.find(v[j] - v[i]) == s.end()) {
					s.insert(v[j] - v[i]);
				}
			}
		}
		cout << s.size() << '\n';
	}
}
