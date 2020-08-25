#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
string in, ans, confirm;
int num;
void go(int ind) {
	if (ind - num >= 0) {
		ans[ind - num] = '0';
	}
	if (ind + num < in.length()) {
		ans[ind + num] = '0';
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> in >> num;
		ans.clear();
		confirm.clear();
		for (int i = 0; i < in.length(); i++) {
			ans.push_back('2');
			confirm.push_back('0');
		}
		for (int i = 0; i < in.length(); i++) {
			if (in[i] == '0') {
				go(i);
			}
		}
		for (int i = 0; i < in.length(); i++) {
			if (ans[i] == '2')ans[i] = '1';
		}
		for (int i = 0; i < in.length(); i++) {
			if (i + num < in.length() && ans[i + num] == '1') {
				confirm[i] = '1';
			}
			if (i - num >= 0 && ans[i - num] == '1') {
				confirm[i] = '1';
			}
		}
		if (confirm != in) {
			cout << "-1\n";
		}
		else cout << ans << '\n';
	}
}
