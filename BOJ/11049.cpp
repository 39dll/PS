#include <iostream>
#include <algorithm>
using namespace std;
int N, r[501], c[501], dp[501][501];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> r[i] >> c[i];
	}
	for (int i = 1; i < N; i++) {
		for (int start = 1; start + i <= N; start++) {
			int end = start + i;
			dp[start][end] = 2147483647;
			for (int j = start; j < end; j++) {
				cout << start << " " << j << " " << end << "\n";
				int k = dp[start][j] + dp[j + 1][end] + r[start] * c[j] * c[end];
				dp[start][end] = min(dp[start][end], k);
			}
		}
	}
	cout << dp[1][N];
}