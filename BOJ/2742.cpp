#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cout << N - i + 1 << "\n";
	}
	return 0;
}