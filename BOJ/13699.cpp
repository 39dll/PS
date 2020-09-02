#include <bits/stdc++.h>
using namespace std;
long long N, dp[36];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
	cout << dp[N];
}