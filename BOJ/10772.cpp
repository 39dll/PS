#include <bits/stdc++.h>
using namespace std;
long long n, k, dp[251][251];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
		dp[i][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= i; j++) {
			if (dp[i][j] != 0)continue;
			dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
		}
	}
	cout << dp[n][k];
}