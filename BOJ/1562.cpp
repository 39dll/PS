#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1000000000;
int N, ans, dp[101][10][1024];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		dp[1][i][1 << i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int k = 0; k <= 1023; k++) {
			dp[i][0][k | (1 << 0)] += dp[i - 1][1][k];
			dp[i][0][k | (1 << 0)] %= MOD;
			dp[i][9][k | (1 << 9)] += dp[i - 1][8][k];
			dp[i][9][k | (1 << 9)] %= MOD;
			for (int j = 1; j <= 8; j++) {
				dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
				dp[i][j][k | (1 << j)] %= MOD;
				dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
				dp[i][j][k | (1 << j)] %= MOD;
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		ans += dp[N][i][1023];
		ans %= MOD;
	}
	cout << ans;
}