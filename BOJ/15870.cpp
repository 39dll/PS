#include <iostream>
using namespace std;
int pib(int a) {
	if (a >= 2) {
		return pib(a - 1) + pib(a - 2);
	}
	else {
		return a;
	}
}
int main() {
	int N, a = 0;
	cin >> N;
	if (N != 0) a = pib(N);
	cout << a;
	return 0;
}