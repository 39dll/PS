#include <bits/stdc++.h>
using namespace std;
long long myabs(long long a) {
	return a >= 0 ? a : -a;
}
int main() {
	int T; cin >> T;
	while (T--) {
		int N;
		vector<int> arr1, arr2, arr3;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int in;
			cin >> in;
			arr1.push_back(in);
		}
		for (int i = 0; i < N; i++) {
			int in;
			cin >> in;
			arr2.push_back(in);
		}
		for (int i = 0; i < N; i++) {
			if (arr2[i] == 0)arr3.push_back(arr1[i]);
		}
		sort(arr3.begin(), arr3.end());
		int it = arr3.size()-1;
		for (int i = 0; i < N; i++) {
			if (arr2[i] == 1)cout << arr1[i] << ' ';
			else {
				cout << arr3[it] << ' ';
				it--;
			}
		}
		cout << '\n';
	}
}
