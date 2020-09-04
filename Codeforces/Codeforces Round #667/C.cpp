#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, x, y;
		int arr[51] = { 0, };
		bool flag = 0;
		cin >> n >> x >> y;
		for (int d = 1; d <= y - x; d++) {
			for (int i = 1; i <= n; i++) {
				arr[i] = 1 + d * (i - 1);
			}
			if (arr[n] < y) {
				for (int i = 1; i <= n; i++) {
					arr[i] += y - arr[n];
				}
				arr[n] = y;
				if (find(arr + 1, arr + n + 1, x) != arr + n + 1) {
					for (int i = 1; i <= n; i++) {
						cout << arr[i] << ' ';
					}
					cout << '\n';
					break;
				}
				else {
					continue;
				}
			}
			else {
				while (find(arr + 1, arr + n + 1, y) == arr + n + 1) {
					for (int i = 1; i <= n; i++) {
						arr[i]++;
					}
				}
				if (find(arr + 1, arr + n + 1, x) != arr + n + 1) {
					for (int i = 1; i <= n; i++) {
						cout << arr[i] << ' ';
					}
					cout << '\n';
					break;
				}
				else {
					continue;
				}
			}
		}
	}
}
