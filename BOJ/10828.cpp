#include <iostream>
#include <string>
using namespace std;
int arr[10001], sz = 0;
void push(int n) {
	arr[sz] = n;
	sz++;
	return;
}
bool empty() {
	if (sz == 0) return 1;
	else return 0;
}
int pop() {
	if (empty()) return -1;
	int a = arr[sz - 1];
	arr[sz - 1] = 0;
	sz--;
	return a;
}
int size() {
	return sz;
}
int top() {
	if (empty()) return -1;
	return arr[sz - 1];
}
int main() {
	int N, temp = 0;;
	string a = "";
	cin >> N;
	while (N--) {
		cin >> a;
		if (a == "push") {
			cin >> temp;
			push(temp);
		}
		else if (a == "top") {
			cout << top() << "\n";
		}
		else if (a == "size") {
			cout << size() << "\n";
		}
		else if (a == "empty") {
			cout << empty() << "\n";
		}
		else if (a == "pop") {
			cout << pop() << "\n";
		}
	}
}