#include <iostream>
#include <algorithm>
using namespace std;
int T, n, s[100001][2], dp[100001][3];//0 = ¾È¶À, 1 = À§, 2 = ¾Æ·¡
int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i <= 1; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> s[j][i];
			}
		}
		dp[1][0] = 0; dp[1][1] = s[1][0]; dp[1][2] = s[1][1];
		for (int i = 2; i <= n; i++) {
			dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
			dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + s[i][0];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + s[i][1];
		}
		cout << max({ dp[n][0],dp[n][1],dp[n][2] }) << "\n";
	}
}