#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	string str(4 * N + 1, '*'), str2(4 * N, ' ');
	for (int i = 0; i < N; i++) {
		cout << str.substr(0, i + 1);
		cout << str2.substr(0, 2 * (N - i - 1));
		cout << str.substr(0, i + 1) << '\n';
	}
	for (int i = N - 2; i >= 0; i--) {
		cout << str.substr(0, i + 1);
		cout << str2.substr(0, 2 * (N - i - 1));
		cout << str.substr(0, i + 1) << '\n';
	}
}