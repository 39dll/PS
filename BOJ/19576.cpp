#include <iostream>
#include <algorithm>
using namespace std;
int N, dp[5001], arr[5001], cnt;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] % arr[j] == 0)dp[i] = max(dp[i], dp[j] + 1);
		}
		cnt = max(cnt, dp[i]);
	}
	cout << N - cnt;
}