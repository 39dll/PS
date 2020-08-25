#include <iostream>
#include <algorithm>
using namespace std;
int N, A[1001], dp[1001][1001], ans;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	dp[1][A[1]] = A[1];
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 1000; j++) {
			if(j < A[i]) dp[i][A[i]] = max(dp[i][A[i]], dp[i - 1][j] + A[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	for (int j = 0; j <= 1000; j++) {
		ans = max(ans, dp[N][j]);
	}
	cout << ans;
}