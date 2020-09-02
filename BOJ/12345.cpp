#include <bits/stdc++.h>
using namespace std;
string in;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		priority_queue<string> pq;
		int N, ans = 0;
		cin >> N; N--;
		cin.ignore();
		getline(cin, in);
		pq.push(in);
		while (N--) {
			getline(cin, in);
			if (pq.top().compare(in) > 0)ans++;
			pq.push(in);
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}
}