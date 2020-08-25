#include <iostream>
#include <algorithm>
#define INF 2100000000
using namespace std;
int n, k;
int dp[100001], coin[101];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		dp[coin[i]] = 1;
	}
	for (int i = 1; i <= k; i++) {
		int mn = INF;
		for (int j = 1; j <= n; j++) {
			if (i - coin[j] >= 0) {
				mn = min(mn, dp[i - coin[j]] + 1);
			}
		}
		dp[i] = mn;
	}
	if (dp[k] == INF) cout << "-1";
	else cout << dp[k];
}