#include <bits/stdc++.h>
using namespace std;
int N, arr[200001];
int dp[200001][2];
long long myabs(long long a) {
	return a >= 0 ? a : -a;
}
int main() {
	int T; cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			dp[i][0] = dp[i][1] = 2100000000;
		}
		dp[0][0] = dp[0][1] = 2100000000;
		dp[1][0] = arr[1];
		dp[1][1] = 2100000000;
		dp[2][0] = arr[1] + arr[2];
		dp[2][1] = arr[1];
		for (int i = 3; i <= N; i++) {
			dp[i][0] = min({ dp[i - 1][1] + arr[i],dp[i - 2][1] + arr[i - 1] + arr[i] });
			dp[i][1] = min({ dp[i - 1][0],dp[i - 2][0] });
		}
		cout << min(dp[N][0], dp[N][1]) << '\n';
	}
}
