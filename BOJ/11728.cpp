#include <iostream>
#include <vector>
using namespace std;
vector<int> a1, a2, a3;
int N, M, ind1 = -1, ind2 = -1, temp;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		a1.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		a2.push_back(temp);
	}
	for (; ind1 < N - 1;) {
		for (; ind2 < M - 1;) {
			if (a1[ind1 + 1] < a2[ind2 + 1]) {
				a3.push_back(a1[ind1 + 1]);
				ind1++;
				break;
			}
			else {
				a3.push_back(a2[ind2 + 1]);
				ind2++;
				continue;
			}
		}
		if (ind1 == N - 1) {
			while (ind2 != M - 1) {
				a3.push_back(a2[ind2 + 1]);
				ind2++;
			}
		}
		if (ind2 == M - 1) {
			while (ind1 != N - 1) {
				a3.push_back(a1[ind1 + 1]);
				ind1++;
			}
		}
	}
	for (int i = 0; i < a3.size(); i++) {
		cout << a3[i] << " ";
	}
}