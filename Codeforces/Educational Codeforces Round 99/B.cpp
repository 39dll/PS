#include <bits/stdc++.h>
using namespace std;
long long dp[2030001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	set<int> s;
	for (int i = 1; i < 2001; i++) {
		s.insert(i * (i + 1) / 2);
	}
	int k = 1;
	for (int i = 1; i <= 1000000; i++) {
		dp[i] = k;
		if (s.find(i + 1) != s.end())dp[i]++;
		if (s.find(i) != s.end())k++;
	}
	int T; cin >> T; while (T--) {
		long long N;
		cin >> N;
		cout << dp[N] << '\n';
	}
}
