#include <iostream>
using namespace std;
int N, K, dp[1001][1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		dp[i][1] = i;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j];
			dp[i][j] %= 1000000003;
		}
	}
	cout << (dp[N - 1][K] + dp[N - 3][K - 1]) % 1000000003;
}