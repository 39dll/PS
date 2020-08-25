#include <iostream>
#include <algorithm>
using namespace std;
int T, K, a[5001], sum[5001] = { 0 }, dp[5001][5001], num[5001][5001];
int main() {
	cin >> T;
	while (T--) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
			num[i - 1][i] = i;
		}
		for (int i = 2; i <= K; i++) {
			for (int start = 0; start + i <= K; start++) {
				int end = start + i;
				dp[start][end] = 2100000000;
				for (int j = num[start][end - 1]; j <= num[start + 1][end]; j++) {
					int t = dp[start][j] + dp[j][end] + sum[end] - sum[start];
					if (dp[start][end] > t) {
						dp[start][end] = t;
						num[start][end] = j;
					}
				}
			}
		}
		cout << dp[0][K] << "\n";
	}
}