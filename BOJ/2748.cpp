#include <iostream>
using namespace std;
int N;
long long int dp[92] = { 0, };
long long int fibo(int n) {
	if (dp[n] == 0 && n >= 2) {
		dp[n] = fibo(n - 1) + fibo(n - 2);
	}
	else if (dp[n] == 0 && n < 2) {
		dp[n] = n;
	}
	return dp[n];
}
int main() {
	cin >> N;
	for (int i = 0; i <= N; i++) {
		fibo(i);
	}
	cout << dp[N];
}