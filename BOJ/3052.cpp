#include <iostream>
using namespace std;
int main() {
	int *a = new int[9];
	int *b = new int[9];
	int *c = new int[41];
	for (int i = 0; i < 42; i++) {
		c[i] = 0;
	}

	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		b[i] = a[i] % 42;
		c[b[i]] = 1;
	}
	a[0] = 0;
	for (int i = 0; i < 42; i++) {
		if (c[i] == 1) a[0]++;
	}
	cout << a[0];
	return 0;
}