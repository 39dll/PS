#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> v;
		if (N == 10000) {
			v.push_back(10000);
			N -= 10000;
		}
		if ((N / 1000) * 1000 != 0) {
			v.push_back((N / 1000) * 1000);
			N -= ((N / 1000) * 1000);
		}
		if ((N / 100) * 100 != 0) {
			v.push_back((N / 100) * 100);
			N -= ((N / 100) * 100);
		}
		if ((N / 10) * 10 != 0) {
			v.push_back((N / 10) * 10);
			N -= ((N / 10) * 10);
		}
		if (N % 10 != 0)v.push_back(N % 10);
		cout << v.size() << '\n';
		for (int i = 0; i < v.size(); i++)cout << v[i] << ' ';
		cout << '\n';
	}
}
