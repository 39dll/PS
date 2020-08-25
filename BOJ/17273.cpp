#include <iostream>
using namespace std;
int main() {
	int N, M, A, B, K, stat = 0;
	cin >> N >> M >> A >> B;
	while (M--) {
		cin >> K;
		if (stat == 0 && K >= A) {
			stat = 1;
		}
		else if (stat == 1 && K >= B) {
			stat = 0;
		}
	}
	if (stat == 0) cout << A;
	else cout << B;
}