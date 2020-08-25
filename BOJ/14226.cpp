#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int S, cnt, dp[2004][2004];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			dp[i][j] = 99999999;
		}
	}
	cin >> S;
	dp[1][0] = 0;
	int r = 100;
	while (r--) {
		for (int i = 1; i <= 1001; i++) {
			for (int j = 0; j <= 1001; j++) {
				dp[i][i] = min(dp[i][j] + 1, dp[i][i]); //복사
														//cout << "dp[" << i << "][" << i << "] = " << dp[i][i] << "\n";
				dp[i + j][j] = min(dp[i][j] + 1, dp[i + j][j]); //붙여넣기
																//cout << "dp[" << i+j << "][" << j << "] = " << dp[i+j][j] << "\n";
				dp[i - 1][j] = min(dp[i][j] + 1, dp[i - 1][j]); //지우기
																//cout << "dp[" << i-1 << "][" << j << "] = " << dp[i-1][j] << "\n";
			}
		}
	}
	int mn = 99999999;
	for (int j = 0; j < 1001; j++) {
		if (dp[S][j] != -1)mn = min(mn, dp[S][j]);
	}
	cout << mn;
}