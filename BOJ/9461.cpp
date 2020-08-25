#include <iostream>
using namespace std;
int N = 0 , M = 0;
int main() {
	cin >> N;
	long long int *p = new long long int[101];
	for (int i = 0; i < N; i++) {
		p[i] = 0;
	}
	p[0] = 1; p[1] = 1; p[2] = 1;
	for (int i = 3; i < 101; i++) {
		p[i] = p[i - 2] + p[i - 3];
	}
	while (N--) {
		cin >> M;
		if (M >= 1) cout << p[M - 1] << "\n";
	}
	return 0;
}