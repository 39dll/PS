#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<string>v;
		for (int i = 0; i < N; i++) {
			string in; cin >> in;
			v.push_back(in);
		}
		vector<vector<int>> psum;
		for (int i = 0; i < N; i++) {
			vector<int> cur(M + 1);
			for (int j = 0; j < M; j++) {
				cur[j + 1] = cur[j] + (v[i][j] == '*');
			}
			psum.push_back(cur);
		}
		long long ans = 0;
		for (int j = 0; j < M; j++) {
			int cur = -1;
			for (int i = 0; i < N; i++) {
				if (v[i][j] == '.') {
					cur = -1;
					continue;
				}
				int st = 0, en = cur + 1;
				int mx = 0;
				while (st <= en) {
					int mid = (st + en) / 2;
					if (mid + j + 1 > M) {
						en = mid - 1;
						continue;
					}
					if (j - mid < 0) {
						en = mid - 1;
						continue;
					}
					if (psum[i][j + mid + 1] - psum[i][j - mid] == mid * 2 + 1) {
						st = mid + 1;
						mx = mid;
					}
					else {
						en = mid - 1;
					}
				}
				cur = mx;
				ans += mx + 1;
			}
		}
		cout << ans << '\n';
	}
}
