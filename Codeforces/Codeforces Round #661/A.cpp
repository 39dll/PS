#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
int t, N;
int arr[51];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> N;
		bool flag = 1;
		for (int i = 0; i < N; i++)cin >> arr[i];
		sort(arr, arr + N);
		for (int i = 0; i < N - 1; i++) {
			if (abs(arr[i] - arr[i + 1]) <= 1)continue;
			else {
				cout << "NO\n";
				flag = 0;
				break;
			}
		}
		if(flag==1)cout << "YES\n";
	}
}
