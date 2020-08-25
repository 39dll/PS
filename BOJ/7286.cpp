#include <iostream>
#include <cstring>
using namespace std;
int N, M, arr[1005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--) {
		memset(arr, 0, sizeof(arr));
		cin >> M;
		char garb;
		int in1, in2;
		for (int i = 0; i < M; i++) {
			cin >> garb >> in1 >> in2;
			for (int j = in1; j < in2; j++) {
				arr[j]++;
			}
		}
		for (int i = 0; i <= 1000; i++) {
			if (arr[i] != 0)cout << (char)(arr[i] + 'A' - 1);
		}
		cout << '\n';
	}
}