#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int T, in, a;
string ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> in;
		a = (in - 1) / 4 + 1;
		ans = "";
		for (int i = 0; i < in - a; i++) {
			ans += "9";
		}
		for (int i = 0; i < a; i++) {
			ans += "8";
		}
		cout << ans << "\n";
	}
}
