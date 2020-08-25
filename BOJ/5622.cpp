#include <iostream>
#include <string>
using namespace std;
int num[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 }, time = 0;
string str;
int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		time += num[str[i]-'A'];
	}
	cout << time;
}