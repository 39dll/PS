#include <bits/stdc++.h>
using namespace std;
int N, M, arr[1001][1001], dp[1001][1001];
char in[1002];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		cin >> in;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = in[j - 1] - '0';
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j]) {
				dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
				ans = max(ans, dp[i][j] * dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	cout << ans;
}