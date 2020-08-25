#include <iostream>
#include <algorithm>
using namespace std;
int T, K, a[501], sum[501] = { 0 }, dp[501][501];
int main() {
	cin >> T;
	while (T--) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 1; i < K; i++) {
			for (int start = 1; start + i <= K; start++) {
				int end = start + i;
				dp[start][end] = 2100000000;
				for (int j = start; j < end; j++) {
					dp[start][end] = min(dp[start][end], dp[start][j] + dp[j + 1][end] + sum[end] - sum[start - 1]);
				}
			}
		}
		cout << dp[1][K] << "\n";
	}
}