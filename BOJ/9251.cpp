#include <iostream>
#include <algorithm>
using namespace std;
char a, A[1002], B[1002];
int dp[1001][1001], M = 0;
int main() {
	cin >> A + 1;
	cin >> B + 1;
	for (int i = 1; A[i]; i++) {
		for (int j = 1; B[j]; j++) {
			if (A[i] == B[j]) {
			dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1] + 1);
			}
			else {
			dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
			}
			M = max(M, dp[i][j]);
		}
	}
	cout << M;
}