#include <iostream>
using namespace std;
int T, n;
long long dp[65][10];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	cin >> T;
	while (T--) {
		cin >> n;
		long long sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += dp[n][i];
		}
		cout << sum << "\n";
	}
}