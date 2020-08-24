#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
//#define int long long
using namespace std;
int t;
int n, arr[100001];
int cnt, ind, ind2;
bool st;
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] == 1 && st == 0) ind++;
			else st = 1;
		}
		if (ind == n) {
			if (ind % 2 == 1) {
				cout << "First\n";
			}
			else {
				cout << "Second\n";
			}
		}
		else {
			if (ind % 2 == 0) {
				cout << "First\n";
			}
			else {
				cout << "Second\n";
			}
		}
		ind = 0; st = 0;
	}
}
