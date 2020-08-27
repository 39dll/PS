#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[200001], w[200001];
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < k; i++)cin >> w[i];
		sort(a, a + n);
		sort(w, w + k);
		long long ans = 0;
		int ptr = n - 1;
		for (int i = 0; i < k; i++) {
			if (w[i] == 1)ans += a[ptr];
			ans += a[ptr];
			ptr--;
		}
		for (int i = 0; i < k; i++)w[i]--;
		for (int i = 0; i < k; i++) {
			if (w[i] == 0)continue;
			ans += a[ptr - w[i] + 1];
			ptr -= w[i];
		}
		cout << ans << '\n';
	}
}
