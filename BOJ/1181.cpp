#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N;
string str[20002];
bool comp(string str1, string str2) {
	if (str1.length() == str2.length()) {
		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] != str2[i])
				return str1[i] < str2[i];
		}
		return 0;
	}
	else return str1.length() < str2.length();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	sort(str, str + N, comp);
	cout << str[0] << "\n";
	for (int i = 1; i < N; i++) {
		if (str[i] != str[i - 1])cout << str[i] << "\n";
	}
}