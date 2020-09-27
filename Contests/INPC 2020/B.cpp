#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long N;
	cin >> N;
	if (N < 0)cout << 32;
	else {
		int ans = 1;
		int k = 1;
		while (1) {
			if (N <= k)break;
			k = k * 2 + 1;
			ans++;
		}
		cout << ans;
	}
}
