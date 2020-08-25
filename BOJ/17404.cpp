#include <iostream>
#include <algorithm>
using namespace std;
int N, cost[1001][3];//R,G,B
int dp[1001][3][3];//ind,last,first
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		dp[1][i][i] = cost[1][i];
	}
	dp[1][0][1] = dp[1][0][2] = dp[1][1][0] = dp[1][1][2] = dp[1][2][0] = dp[1][2][1] = 2100000000;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][0][j] = min(dp[i - 1][1][j], dp[i - 1][2][j]) + cost[i][0];
			dp[i][1][j] = min(dp[i - 1][0][j], dp[i - 1][2][j]) + cost[i][1];
			dp[i][2][j] = min(dp[i - 1][0][j], dp[i - 1][1][j]) + cost[i][2];
		}
	}
	cout << min({ dp[N][0][1],dp[N][0][2],dp[N][1][0],dp[N][1][2],dp[N][2][0],dp[N][2][1] });
}