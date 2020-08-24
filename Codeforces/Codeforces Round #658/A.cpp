#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
//#define int long long
using namespace std;
int t;
int n, m, a[1001], b[1001];
bool out;
vector<int> c;
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	c.clear();
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> b[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i] == b[j]) {
					cout << "YES\n1 " << a[i] << "\n";
					out = 1;
					break;
				}
			}
			if (out == 1) break;
		}
		if (out == 0) cout << "NO\n";
		out = 0;
	}
}
