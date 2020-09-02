#include <iostream>
using namespace std;
long long N, M, dp[10001];
long long calc(long long A, long long B) {
	if (B == 0)return 1;
	if (B == 1) return (A % 1999);
	long long temp = calc(A, B / 2) % 1999;
	if (B % 2 == 0) return temp * temp % 1999;
	else return ((temp * temp) % 1999 * (calc(A, 1))) % 1999;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		if (i < N)dp[i] = calc(2, i - 1);
		if (i == N)dp[i] = calc(2, N) - 1;
		if (i > N) {
			for (int j = 1; j < N; j++) {
				dp[i] += dp[i - j];
				dp[i] %= 1999;
			}
			dp[i] += calc(2, N - 1) * dp[i - N];
			dp[i] %= 1999;
		}
	}
	cout << dp[M];
}