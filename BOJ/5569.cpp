#include <iostream>
using namespace std;
int w, h, dp[101][101][2][2];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> w >> h;
	for (int i = 1; i <= w; i++) {
		dp[i][1][0][0] = 1;
	}
	for (int i = 1; i <= h; i++) {
		dp[1][i][0][1] = 1;
	}
	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			dp[i][j][0][0] += dp[i - 1][j][0][0];
			dp[i][j][0][0] += dp[i - 1][j][1][0];
			dp[i][j][0][0] %= 100000;
			dp[i][j][0][1] += dp[i][j - 1][0][1];
			dp[i][j][0][1] += dp[i][j - 1][1][1];
			dp[i][j][0][1] %= 100000;
			dp[i][j][1][0] += dp[i - 1][j][0][1];
			dp[i][j][1][0] %= 100000;
			dp[i][j][1][1] += dp[i][j - 1][0][0];
			dp[i][j][1][1] %= 100000;
		}
	}
	int ans = 0;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) ans += dp[w][h][i][j];
	cout << ans % 100000;
}