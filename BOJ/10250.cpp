#include <iostream>
using namespace std;
int main() {
	int n, H, W, N, k;
	cin >> n;
	while (n--) {
		cin >> H >> W >> N;
		if (N%H == 0) k = N / H; else k = N / H + 1;
		if (k >= 10) {
			cout << (N - 1) % H + 1 << k << "\n";
		}
		else {
			cout << (N - 1) % H + 1 << "0" << k << "\n";
		}
	}
	return 0;
}