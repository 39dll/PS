#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	long long N; cin >> N;
	if (N % 2 == 0) {
		cout << (N / 2 + 1)*(N / 2 + 1);
	}
	else {
		long long ans = 0, sum = 4;
		for (int i = 1; i <= N; i += 2) {
			ans += sum; sum += 4;
		}
		cout << ans;
	}
}
