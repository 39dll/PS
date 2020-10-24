#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> p;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i + j == N - 1)cout << 4 << ' ';
				else if (i + j == N - 2 || i == N - 1 && j == N - 1)cout << 1 << ' ';
				else cout << 0 << ' ';
			}
			cout << '\n';
		}
	}
}
