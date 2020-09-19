#include <bits/stdc++.h>
using namespace std;
long long ans[100], ans2[100];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long a = 1;
	for (int i = 1; i <= 31; i++) {
		ans[i] = a*(a + 1) / 2;
		ans2[i] = ans2[i - 1] + ans[i];
		a *= 2;
		a += 1;
	}
	int T; cin >> T;
	while (T--) {
		long long N;
		cin >> N;
		int it = 1;
		while (1) {
			if (ans2[it] == N)break;
			if (ans2[it] > N)break;
			it++;
		}
		if (ans2[it] == N)cout << it << '\n';
		else cout << it - 1 << '\n';
	}
}
