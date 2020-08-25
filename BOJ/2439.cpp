#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int ii = N - i; ii >= 1; ii--) {
			cout << " ";
		}
		for (int iii = N - i + 1; iii <= N; iii++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}