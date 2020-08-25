#include <iostream>
using namespace std;
int N, K, in, sum;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> in;
		sum += (in + 1) / 2;
	}
	if (sum >= N)cout << "YES";
	else cout << "NO";
}