#include <iostream>
using namespace std;
int N, k, a1[41] = { 0, }, a2[41] = { 0, };
void fibo(int n) {
	a1[n] = a1[n - 1] + a1[n - 2];
	a2[n] = a2[n - 1] + a2[n - 2];
}
int main() {
	cin >> N;
	a1[0] = 1; a1[1] = 0; a2[0] = 0; a2[1] = 1;
	for (int i = 2; i < 41; i++) {
		fibo(i);
	}
	while (N--) {
		cin >> k;
		cout << a1[k] << " " << a2[k] << "\n";
	}
}