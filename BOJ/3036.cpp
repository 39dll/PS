#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	int k;
	while (b != 0) {
		k = a%b;
		a = b;
		b = k;
	}
	return a;
}
void print(int a, int b) {
	cout << a / gcd(a, b) << "/" << b / gcd(a, b) << "\n";
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int *a = new int[N + 1];
	cin >> a[1];
	for (int i = 2; i <= N; i++) {
		cin >> a[i];
		print(a[1], a[i]);
	}
	return 0;
}