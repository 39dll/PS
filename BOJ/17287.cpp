#include <bits/stdc++.h>
using namespace std;
string in;
int len, mx, cur;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> in;
	len = in.length();
	for (int i = 0; i < len; i++) {
		switch (in[i]) {
		case '(':
			cur += 1;
			break;
		case ')':
			cur -= 1;
			break;
		case '{':
			cur += 2;
			break;
		case '}':
			cur -= 2;
			break;
		case '[':
			cur += 3;
			break;
		case ']':
			cur -= 3;
			break;
		}
		if (in[i] >= '0'&&in[i] <= '9') {
			cout << cur << '\n';
			mx = max(mx, cur);
		}
	}
	cout << mx;
}