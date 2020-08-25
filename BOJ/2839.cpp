#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	if (N == 4 || N == 7) cout << -1;
	else switch (N % 5) {
	case 0: cout << N / 5; break;
	case 1: case 3: cout << N / 5 + 1; break;
	case 2: case 4: cout << N / 5 + 2; break;
	}
	return 0;
}