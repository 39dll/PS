#include <iostream>
using namespace std;
int main() {
	int N, count = 1, layer = 1;
	cin >> N;
	while (1) {
		if (count >= N) {
			break;
		}
		else {
			count += layer * 6;
			layer++;
		}
	}
	cout << layer;
	return 0;
}