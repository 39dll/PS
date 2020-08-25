#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = N; i > 1; i--) {
		for (int j = N - i; j > 0; j--) {
			cout << " ";
		}
		for (int j = 2 * i - 1; j > 0; j--) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N; i++) {
		for (int j = N - i; j > 0; j--) {
			cout << " ";
		}
		for (int j = 2 * i - 1; j > 0; j--) {
			cout << "*";
		}
		cout << "\n";
	}
}