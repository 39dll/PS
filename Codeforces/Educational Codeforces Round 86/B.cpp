#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		string in;
		cin >> in;
		bool con1 = 0, con0 = 0;
		for (int i = 0; i < in.length(); i++) {
			if (in[i] == '0')con0 = 1;
			else con1 = 1;
		}
		if (con1 + con0 == 1)cout << in << '\n';
		else {
			for (int i = 0; i < in.length(); i++) {
				cout << "01";
			}cout << '\n';
		}
	}
}
