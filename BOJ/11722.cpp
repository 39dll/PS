#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, A[1001], dp[1001], m;
int main() {
	cin >> N;
	memset(dp, 1000000000, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		if (dp[i] == 0)dp[i] = 1;
		for (int j = 1; j <= N; j++) {
			if (A[i] < A[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		m = max(m, dp[i]);
	}
	cout << m;
}