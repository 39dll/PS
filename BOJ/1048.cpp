#include <iostream>
#include <algorithm>
using namespace std;
long long dp[50][301][301];
char input[51];
char board[301][301];
int N, M, L;
long long lol = 1000000007;
int sum(int ind, int a, int b, int c, int d) {
	long long ret = 0;
	a = max(a, 1);
	b = max(b, 1);
	c = min(c, N);
	d = min(d, M);
	ret += dp[ind][c][d];
	ret -= dp[ind][a - 1][d];
	ret -= dp[ind][c][b - 1];
	ret += dp[ind][a - 1][b - 1];
	ret += 2 * lol;
	return ret % lol;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> L;
	cin >> input;
	L = -1;
	while (input[++L]);
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	for (int j = 1; j <= N; j++) {
		for (int k = 1; k <= M; k++) {
			dp[0][j][k] = dp[0][j - 1][k] + dp[0][j][k - 1] - dp[0][j - 1][k - 1];
			if (board[j - 1][k - 1] == input[0]) {
				dp[0][j][k]++;
			}
		}
	}
	for (int i = 1; i < L; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (board[j - 1][k - 1] == input[i]) {
					dp[i][j][k] = sum(i - 1, 1, 1, N, M);
					dp[i][j][k] -= sum(i - 1, 1, k - 1, N, k + 1);
					dp[i][j][k] -= sum(i - 1, j - 1, 1, j + 1, M);
					dp[i][j][k] -= sum(i - 1, j - 2, k - 2, j + 2, k + 2);
					dp[i][j][k] += sum(i - 1, j - 2, k - 1, j + 2, k + 1);
					dp[i][j][k] += sum(i - 1, j - 1, k - 2, j + 1, k + 2);
				}
				dp[i][j][k] += dp[i][j - 1][k];
				dp[i][j][k] += dp[i][j][k - 1];
				dp[i][j][k] -= dp[i][j - 1][k - 1];
				dp[i][j][k] += 2 * lol;
				dp[i][j][k] %= lol;
			}
		}
	}
	cout << dp[L - 1][N][M];
}