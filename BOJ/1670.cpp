#include <iostream>
using namespace std;
long long a[10001];
int N;
int main() {
	a[2] = 1;
	for (int n = 4; n <= 10000; n++) {
			a[n] = 2 * a[n - 2] % 987654321;
			for (int i = 2; i < n - 2; i += 2) {
				a[n] += a[i] * a[n - 2 - i];
				a[n] %= 987654321;
			}
			a[n] %= 987654321;
	}
	cin >> N;
	cout << a[N];
	return 0;
}