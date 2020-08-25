#include <iostream>
using namespace std;
int dp[1001][10], N;
int main() {
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	cin >> N;
	cout << (dp[N][0] + dp[N][1] + dp[N][2] + dp[N][3] + dp[N][4] + dp[N][5] + dp[N][6] + dp[N][7] + dp[N][8] + dp[N][9]) % 10007;
}