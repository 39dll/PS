#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string name1, name2, res = "";
int num[204] = { 0, }, point[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 }, temp = -1, leng = 0;
int nums[204][204] = { { 0, }, }, garb;
int main() {
	cin >> garb >> garb;
	cin >> name1 >> name2;
	if (name1.length() == name2.length()) {
		for (int i = 0; i < name1.length(); i++){
			res += name1[i];
			res += name2[i];
		}
	}
	else if (name1.length() < name2.length()) {
		for (int i = 0; i < name1.length(); i++) {
			res += name1[i];
			res += name2[i];
		}
		for (int i = name1.length(); i < name2.length(); i++) {
			res += name2[i];
		}
	}
	else {
		for (int i = 0; i < name2.length(); i++) {
			res += name1[i];
			res += name2[i];
		}
		for (int i = name2.length(); i < name1.length(); i++) {
			res += name1[i];
		}
	}
	for (int i = 0; i <= 204; i++) {
		num[i] = point[res[i] - 'A'];
		if (num[i] != 0) { leng++; nums[0][i] = num[i]; }
		else break;
	}
	for (int i = 0; i < leng - 2; i++) {
		for (int j = 0; j < leng - i; j++) {
			nums[i + 1][j] = (nums[i][j] + nums[i][j + 1]) % 10;
		}
	}
	if (nums[leng - 2][0] == 0) {
		cout << nums[leng - 2][1] << "%";
	}
	else {
		cout << nums[leng - 2][0] << nums[leng - 2][1] << "%";
	}
	return 0;
}