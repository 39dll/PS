#include <bits/stdc++.h>
using namespace std;
int N, uf[5001];
int find(int a) {
	if (uf[a] == a) return a;
	return uf[a] = find(uf[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) uf[b] = a;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> v(N + 1);
		queue<pair<int, int>> q, ans;
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				if (i != j) {
					if (v[i] != v[j])q.push({ i,j });
				}
			}
		}
		for (int i = 1; i <= N; i++) uf[i] = i;
		int cnt = 0;
		while (!q.empty()) {
			if (cnt == N - 1)break;
			int st, en;
			tie(st, en) = q.front(); q.pop();
			if (find(st) == find(en))continue;
			merge(st, en);
			ans.push({ st, en });
			cnt++;
		}
		if (cnt != N - 1)cout << "NO\n";
		else {
			cout << "YES\n";
			while (!ans.empty()) {
				cout << ans.front().first << ' ' << ans.front().second << '\n';
				ans.pop();
			}
		}
	}
}
