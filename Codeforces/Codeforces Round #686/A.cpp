#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N - 1; i++) {
			cout << i + 1 << ' ';
		}
		cout << 1 << '\n';
	}
}
