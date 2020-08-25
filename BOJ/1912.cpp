#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100001], dp[100001], m = -9999; //i¹øÂ° ÀÎµ¦½º±îÁö Å½»ö
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + a[i], a[i]);
		m = max(m, dp[i]);
	}
	cout << m;
}