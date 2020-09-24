#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> v(N);
		int psum[32] = { 0 };
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			long long a = 1;
			for (int j = 0; j < 33; j++) {
				if (v[i] <= a) {
					a = j;
					break;
				}
				a = a * 2 + 1;
			}
			ans += psum[a];
			psum[a]++;
		}
		cout << ans << '\n';
	}
}
