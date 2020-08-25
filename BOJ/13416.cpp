#include <iostream>
#include <algorithm>
using namespace std;
int temp1, temp2, temp3;
int T, N, cnt = 0;
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> temp1 >> temp2 >> temp3;
			cnt += max({ temp1, temp2, temp3, 0 });
		}
		cout << cnt << "\n";
		cnt = 0;
	}
}