#include <iostream>
using namespace std;
long long dp[101][10][6], N, ans;
int main() {
	for (int i = 0; i <= 9; i++) {
		dp[1][i][3] = 1;
	}
	for (int i = 2; i <= 100; i++) {
		dp[i][0][1] = dp[i - 1][1][2];
		dp[i][0][2] = dp[i - 1][1][3] + dp[i - 1][1][4] + dp[i - 1][1][5];
		dp[i][0][2] %= 1000000007;
		dp[i][9][4] = dp[i - 1][8][3] + dp[i - 1][8][2] + dp[i - 1][8][1];
		dp[i][9][4] %= 1000000007;
		dp[i][9][5] = dp[i - 1][8][4];
		for (int j = 1; j <= 8; j++) {
			dp[i][j][1] = dp[i - 1][j + 1][2];
			dp[i][j][2] = dp[i - 1][j + 1][3] + dp[i - 1][j + 1][4] + dp[i - 1][j + 1][5];
			dp[i][j][2] %= 1000000007;
			dp[i][j][4] = dp[i - 1][j - 1][3] + dp[i - 1][j - 1][2] + dp[i - 1][j - 1][1];
			dp[i][j][4] %= 1000000007;
			dp[i][j][5] = dp[i - 1][j - 1][4];
		}
	}
	cin >> N;
	for (int i = 0; i <= 9; i++) {
		for (int j = 1; j <= 5; j++) {
			ans += dp[N][i][j];
			ans %= 1000000007;
		}
	}
	cout << ans;
}