#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int dp[201][201];
string A, B;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (cin >> A >> B) {
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= A.length(); i++) {
			for (int j = 1; j <= B.length(); j++) {
				if (A[i - 1] == B[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[A.length()][B.length()] << '\n';
	}
}