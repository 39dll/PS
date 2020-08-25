#include <iostream>
using namespace std;
long long N, t = 1;
int main() {
	cin >> N;
	while (N > t * 10) {
		N += 5 * t;
		t *= 10;
		N -= N % t;
	}
	cout << N << '\n';
}