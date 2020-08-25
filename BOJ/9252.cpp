#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string A, B;
int dp[1001][1001];
int main() {
	cin >> A;
	cin >> B;
	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			if (A[i-1] == B[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[A.length()][B.length()] << '\n';
	int i = A.length();
	int j = B.length();
	string ans = "";
	while (dp[i][j] != 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			ans = A[i - 1] + ans;
			i--;
			j--;
		}
	}
	cout << ans;
}