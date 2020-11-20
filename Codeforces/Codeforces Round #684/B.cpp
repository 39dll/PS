#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {

		int N, K; cin >> N >> K;

		vector<long long> v(N*K);
		for (int i = 0; i < N*K; i++)cin >> v[i];
		long long res = 0;
		for (int k = K*((N - 1) / 2); k < N*K; k += N - (N - 1) / 2) {
			res += v[k];
		}
		cout << res << '\n';
	}
}
