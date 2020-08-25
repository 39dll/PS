#include <iostream>
using namespace std;
int M, N;
long long dp[10001];
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		dp[i] = 1;
	}
	for (int i = M; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - M]) % 1000000007;
	}
	cout << dp[N];
}