#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;
int t, N;
int w[51];
int mx, mxnum, ans;
bool used[51];
map<int, int> m;//sum, cnt
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> w[i];
			used[i] = 0;
		}
		m.clear();
		for (int s = 2; s <= 100; s++) {
			for (int i = 1; i < s; i++) {
				if (count(w+1, w + N+1, i)) {
					m[s] += min(count(w + 1, w + N + 1, i), count(w + 1, w + N + 1, s - i));
				}
			}
		}
		/*
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				if (i == j)continue;
				m[w[i] + w[j]]++;
			}
		}
		*/
		mx = 0; mxnum = 0; ans = 0;
		for (auto i : m) {
			if (mx < i.second) {
				mxnum = i.first;
			}
			mx = max(mx, i.second);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (used[i] || used[j])continue;
				if (i == j)continue;
				if (w[i] + w[j] == mxnum) {
					used[i] = used[j] = 1;
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}
