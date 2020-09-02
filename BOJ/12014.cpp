#include <bits/stdc++.h>
using namespace std;
int N, K, ans, arr[100001];
vector<int> dp;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++)cin >> arr[i];
		dp.clear();
		dp.push_back(0);
		ans = 0;
		for (int i = 1; i <= N; i++) {
			int cur = arr[i];
			auto lb = lower_bound(dp.begin(), dp.end(), cur) - dp.begin();
			if (lb >= dp.size())dp.push_back(cur);
			else dp[lb] = cur;
			ans = max(ans, (int)lb);
		}
		cout << "Case #" << t << '\n';
		cout << (ans >= K) << '\n';
	}
}