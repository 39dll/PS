#include <iostream>
using namespace std;
int n, dp[1001];
int main() {
	cin >> n;
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= 1000; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}
	cout << dp[n];
}