#include <iostream>
#include <algorithm>
using namespace std;
int t;
int n, arr[200002];
bool decr;
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[n - i + 1];//n~1
		}
		if (n == 1) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 2; i <= n; i++) {
			if (decr == 0) {
				if (arr[i] < arr[i - 1]) {
					decr = 1;
				}
			}
			else {
				if (arr[i] > arr[i - 1]) {
					cout << n - i + 1 << "\n";
					break;
				}
			}
			if (i == n) cout << 0 << "\n";
		}
		decr = 0;
	}
}
