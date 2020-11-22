#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> p;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {

		long long N; cin >> N;
		int cnt = 0;
		while (1) {
			if (N == 2) {
				cout << cnt + 1 << '\n';
				break;
			}
			if (N == 1) {
				cout << cnt << '\n';
				break;
			}
			if (N % 2 == 1) {
				N--; cnt++;
				continue;
			}
			N = 2; cnt++;
			continue;
		}
	}
}
