#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int in;
		cin >> in;
		v.push_back(in);
	}
	sort(v.begin(), v.end());
	if (N == 1) {
		cout << "0\n";
		cout << v[0] << '\n';
		return 0;
	}
	if (N == 2) {
		cout << "0\n";
		cout << v[0] << ' ' << v[1] << '\n';
		return 0;
	}
	vector<int> ans(100001);
	if (N % 2 == 1) {
		for (int i = 1; i <= N / 2; i++) {
			ans[2 * i - 2] = v[i + N / 2 - 1];
			ans[2 * i - 1] = v[i - 1];
		}
		ans[N - 1] = v[N - 1];
	}
	else {
		for (int i = 1; i <= N / 2; i++) {
			ans[2 * i - 2] = v[i + N / 2 - 1];
			ans[2 * i - 1] = v[i - 1];
		}
	}
	int cnt = 0;
	for (int i = 1; i < N - 1; i++) {
		if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])cnt++;
	}
	cout << cnt << '\n';
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
}
