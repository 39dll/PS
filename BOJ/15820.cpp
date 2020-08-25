#include <iostream>
using namespace std;
int N, M;
int in1, in2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> in1 >> in2;
		if (in1 == in2) continue;
		else {
			cout << "Wrong Answer";
			return 0;
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> in1 >> in2;
		if (in1 == in2) continue;
		else {
			cout << "Why Wrong!!!";
			return 0;
		}
	}
	cout << "Accepted";
}