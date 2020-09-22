#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		long long N, M;
		cin >> N >> M;
		if (N < M)swap(N, M);
		long long ans = 0;
		if (M % 2 == 0) {
			if (N % 2 == 0) {
				ans = M*N / 2;
			}
			else {
				ans = M*N / 2;
			}
		}
		else {
			if (N % 2 == 0) {
				ans = (M*N) / 2;
			}
			else {
				ans = (M*N) / 2 + 1;
			}
		}
		cout << ans << '\n';
	}
}
