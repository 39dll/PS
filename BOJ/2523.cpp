#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int ii = 1; ii <= i; ii++) {
			cout << "*";
		}
		cout << "\n";
	}
		for(int i = 2*N-1;i>=N+1;i--) {
			for (int ii = i-N; ii >= 1; ii--) {
				cout << "*";
			}
			cout << "\n";
		}
	return 0;
}