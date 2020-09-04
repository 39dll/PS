#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, J, left, right;
	cin >> N >> M >> J;
	left = 1; right = M;
	int ans = 0;
	for (int i = 0; i < J; i++) {
		int loc;
		cin >> loc;
		if (loc <= right && loc >= left)continue;
		if (loc < left) {
			ans += left - loc;
			left = loc;
			right = loc + M - 1;
			continue;
		}
		if (loc > right) {
			ans += loc - right;
			right = loc;
			left = loc - M + 1;
			continue;
		}
	}
	cout << ans;
}