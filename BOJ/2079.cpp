#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N, dp2[2501];
bool dp[2501][2501];
string str;
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	str = " " + str;
	for (int i = 1; i < str.length(); i++) {
		dp[i][i] = 1;
		dp[i - 1][i] = str[i - 1] == str[i];
	}
	for (int len = 3; len < str.length(); len++) {
		for (int start = 1; start + len <= str.length(); start++) {
			int end = len + start - 1;
			dp[start][end] = dp[start + 1][end - 1] && (str[start] == str[end]);
		}
	}
	for (int i = 1; i < str.length(); i++) {
		dp2[i] = 1000000007;
		for (int j = 1; j <= i; j++) {
			if (dp[j][i])dp2[i] = min(dp2[i], dp2[j - 1] + 1);
		}
	}
	cout << dp2[str.length() - 1];
}