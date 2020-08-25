#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string A, B, C;
int dp[101][101][101];
int main() {
	cin >> A >> B >> C;
	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			for (int k = 1; k <= C.length(); k++) {
				if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] +1;
				}
				else {
					dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1] });
				}
			}
		}
	}
	cout << dp[A.length()][B.length()][C.length()];
}