#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int R;
	double pi = 3.1415926535897932384626433;
	cin >> R;
	printf("%.6lf\n%.6lf", double(pi * R * R), double(R * R * 2));
	return 0;
}