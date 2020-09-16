#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, s;
		cin >> n >> s;
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			int in1, in2;
			cin >> in1 >> in2;
			if (in1 == s || in2 == s)cnt++;
		}
		if (cnt == 1 || cnt == 0) {
			cout << "Ayush\n";
			continue;
		}
		else {
			if (n % 2 == 0) cout << "Ayush\n";
			else cout << "Ashish\n";
		}
	}
}
