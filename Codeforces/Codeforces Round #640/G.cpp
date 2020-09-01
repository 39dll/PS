#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N == 2 || N == 3) {
			cout << "-1\n";
			continue;
		}
		if (N % 2 == 1) {
			for (int i = N; i >= 1; i -= 2) {
				cout << i << ' ';
			}
			cout << "4 2 ";
			for (int i = 6; i < N; i += 2) {
				cout << i << ' ';
			}
			cout << '\n'; continue;
		}
		else {
			for (int i = N - 1; i >= 1; i -= 2) {
				cout << i << ' ';
			}
			cout << "4 2 ";
			for (int i = 6; i < N; i += 2) {
				cout << i << ' ';
			}
			if (N != 4)cout << N << ' ';
			cout << '\n'; continue;
		}
	}
}
