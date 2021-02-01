#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {
		long long N;;
		string str; cin >> str;
		N = str.length();
		if (N == 1) {
			cout << "0\n";
			continue;
		}
		vector<long long>dp[26][26];
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				dp[i][j].resize(2, 9999999);
			}
		}
		if (str[0] == str[1]) {
			for (int i = 0; i < 26; i++) {
				if (i != str[0] - 'a')dp[str[0] - 'a'][i][0] = 1;
				if (i != str[1] - 'a')dp[i][str[1] - 'a'][0] = 1;
			}
		}
		else {
			dp[str[0] - 'a'][str[1] - 'a'][0] = 0;
		}
		for (int i = 3; i <= N; i++) {
			int cur = str[i - 1] - 'a';
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < 26; k++) {
					if (cur == j || cur == k)
						for (int l = 0; l < 26; l++) {
							if (l != k&&l != j)dp[k][l][1] = min(dp[k][l][1], dp[j][k][0] + 1);
						}
					else dp[k][cur][1] = min(dp[k][cur][1], dp[j][k][0]);
				}
			}
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < 26; k++) {
					dp[j][k][0] = dp[j][k][1];
					dp[j][k][1] = 9999999;
				}
			}
		}
		long long ans = 2100000000;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				ans = min(dp[i][j][0], ans);
			}
		}
		cout << ans << '\n';
	}
}
