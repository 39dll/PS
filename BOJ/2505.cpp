#include <iostream>
#include <vector>
using namespace std;
int N, arr[10001], arr2[10001], input, ind, x1, x2, x3, x4;
vector<int> temp;
bool check(int *arr) {
	for (int i = 1; i <= N; i++) {
		if (arr[i] != i) return 0;
	}
	return 1;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		arr[i] = input;
		arr2[i] = input;
	}
	if (check(arr)) {
		cout << "1 1\n1 1";
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		if (arr[i] != i) {
			x1 = i;
			for (int j = x1; j <= N; j++) {
				temp.push_back(arr[j]);
				if (arr[j] == x1) {
					x2 = j; break;
				}
			}
		}
		if (x1 != 0) {
			for (int j = 0; j <= x2 - x1; j++) {
				arr[j + x1] = temp[x2 - x1 - j];
			}
			temp.clear();
			break;
		}
	}
	if (check(arr)) {
		cout << "1 1\n" << x1 << " " << x2 << "\n";
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		if (arr[i] != i) {
			x3 = i;
			for (int j = x3; j <= N; j++) {
				temp.push_back(arr[j]);
				if (arr[j] == x3) {
					x4 = j; break;
				}
			}
		}
		if (x3 != 0) {
			for (int j = 0; j <= x4 - x3; j++) {
				arr[j + x3] = temp[x4 - x3 - j];
			}
			temp.clear();
			break;
		}
	}
	if (check(arr)) {
		cout << x1 << " " << x2 << "\n" << x3 << " " << x4;
		return 0;
	}
	x1 = x2 = x3 = x4 = 0;
	for (int i = N; i >= 1; i--) {
		if (arr2[i] != i) {
			x2 = i;
			for (int j = x2; j >= 1; j--) {
				temp.push_back(arr2[j]);
				if (arr2[j] == x2) {
					x1 = j; break;
				}
			}
		}
		if (x2 != 0) {
			for (int j = 0; j <= x2 - x1; j++) {
				arr2[j + x1] = temp[j];
			}
			temp.clear();
			break;
		}
	}
	for (int i = N; i >= 1; i--) {
		if (arr2[i] != i) {
			x4 = i;
			for (int j = x4; j >= 1; j--) {
				temp.push_back(arr2[j]);
				if (arr2[j] == x4) {
					x3 = j; break;
				}
			}
		}
		if (x4 != 0) {
			for (int j = 0; j <= x4 - x3; j++) {
				arr2[j + x3] = temp[j];
			}
			temp.clear();
			break;
		}
	}
	cout << x1 << " " << x2 << "\n" << x3 << " " << x4;
}