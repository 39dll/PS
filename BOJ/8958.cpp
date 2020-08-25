#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int N, streak = 0, sum = 0;
	char arr[80];
	cin >> N;
	while (N--) {
		cin >> arr;
		for (int i = 0; i < strlen(arr); i++) {
			if (arr[i] == 'O') {
				streak++;
				sum += streak;
			}
			else {
				streak = 0;
			}
		}
		cout << sum << "\n";
		streak = 0;
		sum = 0;
	}
	return 0;
}