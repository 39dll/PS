#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		if (N < M)swap(N, M);
		int res = 0;
		res += 2 * M;
		if (N != M) res += 2 * (N - M) - 1;
		cout << res << '\n';
	}
}
