#include <iostream>
using namespace std;
int main() {
	int N, count = 1, layer = 2;
	cin >> N;
	while (1) {
		if (count >= N) {
			break;
		}
		else {
			count += layer;
			layer++;
		}
	}
	if (layer % 2 == 0) {
		cout << count - N + 1 << "/" << layer - (count - N + 1);
	}
	else {
		cout << layer - (count - N + 1) << "/" << count - N + 1;
	}
	return 0;
}