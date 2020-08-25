#include <iostream>
using namespace std;
long long T, n, dp[1000001];
int main() {
	cin >> T;
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		dp[i] %= 1000000009;
	}
	while (T--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}