#include <bits/stdc++.h>
using namespace std;
vector<int> ans[200001];
vector<int> sz(200001);
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	long long N, K;
	cin >> N >> K;
	vector<int> v(N), v2(200001);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < K; i++) {
		cin >> v2[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		auto it = lower_bound(sz.begin(), sz.end(), v2[v[i] - 1]) - sz.begin() - 1;
		ans[it].push_back(v[i]);
		sz[it]++;
	}
	int cnt = 0;
	for (int i = 0; i < 200001; i++) {
		if (ans[i].size() != 0)cnt++;
	}
	cout << cnt << '\n';
	for (int i = 0; i < 200001; i++) {
		if (ans[i].size() == 0)continue;
		cout << ans[i].size() << ' ';
		for (int p : ans[i]) {
			cout << p << ' ';
		}cout << '\n';
	}
}
