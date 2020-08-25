#include <iostream>
#include <algorithm>
using namespace std;
long long dp[32][32];
int T, N, M;
int main() {
	dp[0][0] = 1; dp[1][0] = 1; dp[1][1] = 1;
	for (int i = 2; i <= 31; i++) {
		dp[i][0] = 1; dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cout << dp[max(N, M)][min(N, M)] << "\n";
	}
}