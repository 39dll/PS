#include <iostream>
using namespace std;
int d(int arg) {
	int d0, d1, d2, d3;
	d0 = arg % 10;
	d1 = arg % 100 / 10;
	d2 = arg % 1000 / 100;
	d3 = arg / 1000;
	return arg + d0 + d1 + d2 + d3;
}
int main() {
	int *p = new int[100000];
	for (int i = 1; i <= 100000; i++) {
		p[i] = 0;
	}
	for (int i = 1; i <= 10000; i++) {
			p[d(i)] = 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (p[i] == 0) cout << i << "\n";
	}
}