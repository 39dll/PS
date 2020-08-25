#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	if (N % 2 == 0) {
		for (int i = 1; i <= 2 * N; i++) {
			if (i % 2 == 1) {
				for (int j = N / 2; j > 0; j--) {
					cout << "* ";
				}
				cout << "\n";
			}
			else {
				for (int j = N / 2; j > 0; j--) {
					cout << " *";
				}
				cout << "\n";
			}
		}
	}
	if (N % 2 == 1) {
		for (int i = 1; i <= 2 * N; i++) {
			if (i % 2 == 1) {
				for (int j = (N - 1) / 2; j > 0; j--) {
					cout << "* ";
				}
				cout << "*\n";
			}
			else {
				for (int j = (N - 1) / 2; j > 0; j--) {
					cout << " *";
				}
				cout << "\n";
			}
		}
	}
}