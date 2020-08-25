#include <iostream>
using namespace std;
int N, jul[1001], tap[1001], sub[1002], sum;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> jul[i];
	for (int i = 1; i <= N; i++) { cin >> tap[i]; sub[i] = jul[i] - tap[i]; }
	for (int i = 1; i <= N + 1; i++) sum += (sub[i] - sub[i - 1] > 0) * (sub[i] - sub[i - 1]);
	cout << sum;
}