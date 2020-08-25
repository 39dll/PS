#include <iostream>
#include <algorithm>
using namespace std;
int N, K, W[100001], V[100001], dp[100001][1001], m = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//dp[i][j] = 가방의 크기가 i일 때, j번째 물건까지 탐색하여 담는 최대 가치
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
		dp[0][i] = 0;
		dp[i][0] = 0;
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (i < W[j]) dp[i][j] = dp[i][j - 1];
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - W[j]][j-1] + V[j]);
			}
		}
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			m = max(m, dp[i][j]);
		}
	}
	cout << m;
	return 0;
}