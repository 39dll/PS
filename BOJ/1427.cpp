#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int j(int a, int b) {
	return (a % int(pow(10, b + 1))) / pow(10, b);
}
int main() {
	int N, k;
	cin >> N;
	for (int i = 9; i >= 0; i--) {
		if (N >= pow(10, i)) { k = i; break; }
	}
	int *a = new int[k + 1];
	for (int i = 0; i <= k; i++) {
		a[i] = j(N, i);
	}
	sort(a, a + k + 1);
	for (int i = k; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}