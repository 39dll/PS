#include <iostream>
using namespace std;
int N;
int main() {
	cin >> N;
	long long int *p = new long long int[N + 1];
	for (int i = 0; i < N; i++) {
		p[i] = 0;
	}
	p[0] = 1; p[1] = 2;
	for (int i = 2; i < N; i++) {
		p[i] = p[i - 1] + p[i - 2];
		p[i] = p[i] % 15746;
	}
	if (N >= 1) cout << p[N - 1];
	else cout << 0;
	return 0;
}