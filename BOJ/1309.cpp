#include <iostream>
using namespace std;
int N;
int dp[100001][3];//0 = 사자 0, 1 = 사자 왼쪽, 2 = 사자 오른쪽
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][0] %= 9901;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][1] %= 9901;
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][2] %= 9901;
	}
	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
}