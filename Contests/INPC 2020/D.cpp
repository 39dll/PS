#include<bits/stdc++.h>
using namespace std;
long long dp[11];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long H, Y;
	cin >> H >> Y;
	dp[0] = H;
	for (int i = 1; i <= 10; i++) {
		dp[i] = max(dp[i], (long long)floor(dp[i - 1] * 1.05));
		if (i >= 3)dp[i] = max(dp[i], (long long)floor(dp[i - 3] * 1.2));
		if (i >= 5)dp[i] = max(dp[i], (long long)floor(dp[i - 5] * 1.35));
	}
	cout << dp[Y];
}
