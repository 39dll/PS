#include <iostream>
#include <algorithm>
using namespace std;
int N, dp[1001] = { 0 }, p[1001];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		dp[i] = 2100000000;
	}
	dp[1] = p[1];
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i] = min(dp[i], p[i - j] + dp[j]);
		}
	}
	cout << dp[N];
}