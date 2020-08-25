#include <iostream>
#include <map>
#include <string>
using namespace std;
int time1, time2, time3;//시작 시작, 끝나는 시간, 마지막
map<string, int> m, m2;
int getTime(string str) {
	return stoi(str.substr(0, 2) + str.substr(3, 2));
}
int main() {
	string in;
	cin >> in;
	time1 = getTime(in);
	cin >> in;
	time2 = getTime(in);
	cin >> in;
	time3 = getTime(in);
	int tempTime;
	string tempName;
	while (cin >> in) {
		tempTime = getTime(in);
		cin >> tempName;
		if (tempTime <= time1) {
			m[tempName] = 1;
		}
		else if (tempTime >= time2 && tempTime <= time3) {
			if (m[tempName] == 1)m2[tempName] = 1;
		}
	}
	cout << m2.size();
}