#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	string str(2 * N + 1, '*'), str2(N, ' ');
	for (int i = N - 1; i >= 0; i--) {
		cout << str2.substr(0, N - i - 1);
		cout << str.substr(0, 2 * i + 1) << '\n';
	}
}