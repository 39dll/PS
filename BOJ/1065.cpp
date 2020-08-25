#include <iostream>
using namespace std;
bool d(int arg) {
	int d0, d1, d2, d3;
	d0 = arg % 10;
	d1 = arg % 100 / 10;
	d2 = arg / 100;
	if (arg < 100) return 1;
	else if (d0 + d2 == d1 * 2) return 1; else return 0;
}
int main() {
	int N, count = 0;
	int *p = new int[1000];
	for (int i = 1; i <= 1000; i++) {
		p[i] = d(i);
	}
	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (p[i] == 1) count++;
	}
	cout << count;
	return 0;
}