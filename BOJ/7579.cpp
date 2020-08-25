#include <iostream>
#include <algorithm>
using namespace std;
int N, M, m[101], c[101], dp[10001];
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> m[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 10001; j >= c[i]; j--) {
			dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
		}
	}
	int a = 1;
	while (dp[a] < M) {
		a++;
	}
	cout << a << "\n";
}