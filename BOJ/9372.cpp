#include <iostream>
using namespace std;
int t, n, m;
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << n - 1 << '\n';
		for (int i = 1; i <= m; i++)cin >> n >> n;
	}
}