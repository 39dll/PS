#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		map<int, int> m;
		for (int i = 0; i < N; i++) {
			int in; cin >> in;
			m[in]++;
		}
		if (m.size() != N)cout << "YES\n";
		else cout << "NO\n";
	}
}
