#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	string str(N, '*');
	while (N--) {
		cout << str.substr(0, N + 1) << '\n';
	}
}