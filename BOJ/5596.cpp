#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
	for (int i = 0; i < 4; i++) {
		int n; cin >> n;
		a += n;
	}
	for (int i = 0; i < 4; i++) {
		int n; cin >> n;
		b += n;
	}
	cout << max(a, b);
}