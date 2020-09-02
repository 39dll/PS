#include <bits/stdc++.h>
using namespace std;
int N, ans, arr[1000001];
vector<int> dp;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	dp.push_back(-1000000001);
	for (int i = 1; i <= N; i++) {
		int cur = arr[i];
		auto lb = lower_bound(dp.begin(), dp.end(), cur) - dp.begin();
		if (lb >= dp.size())dp.push_back(cur);
		else dp[lb] = cur;
		ans = max(ans, (int)lb);
	}
	cout << ans;
}