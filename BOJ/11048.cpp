#include <iostream>
#include <algorithm>
using namespace std;
int N, M, mp[1001][1001], dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> mp[i][j];
		}
	}
	dp[1][1] = mp[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == 1 && j == 1) continue;
			if (i == 1) {
				dp[i][j] = dp[i][j - 1] + mp[i][j];
				continue;
			}
			if (j == 1) {
				dp[i][j] = dp[i - 1][j] + mp[i][j];
				continue;
			}
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + mp[i][j];
		}
	}
	cout << dp[N][M];
}