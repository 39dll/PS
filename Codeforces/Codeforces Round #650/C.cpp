#include <bits/stdc++.h>
using namespace std;
bool good[200001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		string str;
		int n, k;
		cin >> n >> k >> str;
		for (int i = 0; i < n; i++) {
			good[i] = 1;
		}
		int ptr = -1; bool flag = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == '1') {
				if (flag = 0) {
					ptr = min(i + k, n - 1);
					for (int j = 0; j <= k; j++) {
						if (i + j < n) {
							good[i + j] = 0;
						}
					}
					flag = 1;
				}
				
				else {
					if (ptr > i) {
						for (int j = ptr; j <= i + k; j++) {
							if (j < n) {
								good[j] = 0;
							}
						}
						ptr = min(i + k, n - 1);
					}
					else {
						ptr = min(i + k, n - 1);
						for (int j = 0; j <= k; j++) {
							if (i + j < n) {
								good[i + j] = 0;
							}
						}
					}
				}
			}
		}
		ptr = n; flag = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (str[i] == '1') {
				if (flag = 0) {
					ptr = max(i - k, 0);
					for (int j = 0; j <= k; j++) {
						if (i - j >= 0) {
							good[i - j] = 0;
						}
					}
					flag = 1;
				}

				else {
					if (ptr < i) {
						for (int j = ptr; j >= i - k; j--) {
							if (j >= 0) {
								good[j] = 0;
							}
						}
						ptr = max(i - k, 0);
					}
					else {
						ptr = max(i - k, 0);
						for (int j = 0; j <= k; j++) {
							if (i - j >= 0) {
								good[i - j] = 0;
							}
						}
					}
				}
			}
		}
		int ans = 0, streak = -1;
		for (int i = 0; i < n; i++) {
			if (good[i] == 1) {
				if (streak == -1) {
					ans++;
					streak = 1;
					continue;
				}
				else {
					if (streak > k) {
						ans++;
						streak = 1;
						continue;
					}
				}
			}
			if (streak == -1) {
				continue;
			}
			streak++;
		}
		cout << ans << '\n';
	}
}
