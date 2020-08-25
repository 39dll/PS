#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		while (N%i == 0) {
			N /= i;
			cout << i << "\n";
		}
	}
	return 0;
}