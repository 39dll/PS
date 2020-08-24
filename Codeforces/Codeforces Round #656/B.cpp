#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int t;
int n, temp;
map<int, int> m;
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= 2 * n; i++) {
			cin >> temp;
			if (m[temp] == 0) {
				cout << temp << " ";
				m[temp]++;
			}
			else continue;
		}
		cout << "\n";
		m.clear();
	}
}
