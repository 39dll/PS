#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		if (N < K) {
			cout << "NO\n";
			continue;
		}
		if ((N - K) % 2 == 0) {
			cout << "YES\n";
			for (int i = 0; i < K - 1; i++) {
				cout << "1 ";
			}
			cout << N - K + 1 << '\n';
			continue;
		}
		if ((N - K) % 2 == 1) {
			if (N % 2 == 1) {
				cout << "NO\n";
				continue;
			}
			if (N % 2 == 0) {
				if (N <= 2 * (K - 1)) {
					cout << "NO\n";
					continue;
				}
				cout << "YES\n";
				for (int i = 0; i < K - 1; i++) {
					cout << "2 ";
				}
				cout << N - 2 * (K - 1) << '\n';
				continue;
			}
		}
	}
}
