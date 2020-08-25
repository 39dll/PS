#include <iostream>
using namespace std;
int N, num[2001], M, S, E;
bool dp[2001][2001];
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		dp[i][i] = 1;
		dp[i - 1][i] = num[i - 1] == num[i];
	}
	for (int length = 3; length <= N; length++) {
		for (int start = 1; start + length <= N + 1; start++) {
			int end = length + start - 1;
			dp[start][end] = dp[start + 1][end - 1] && (num[start] == num[end]);
		}
	}
	cin >> M;
	while (M--) {
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}
}