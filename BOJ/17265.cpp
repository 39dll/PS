#include <iostream>
#include <algorithm>
using namespace std;
char pan[6][6];
int maxv[6][6];
int minv[6][6];
int N, temp1, temp2, temp3, temp4, tem1, tem2, tem3, tem4;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> pan[i][j];
		}
	}
	maxv[1][1] = pan[1][1] - '0';
	minv[1][1] = pan[1][1] - '0';
	switch (pan[1][2]) {
	case '*': maxv[1][3] = maxv[1][1] * (pan[1][3] - '0');
		minv[1][3] = minv[1][1] * (pan[1][3] - '0'); break;
	case '+': maxv[1][3] = maxv[1][1] + (pan[1][3] - '0');
		minv[1][3] = minv[1][1] + (pan[1][3] - '0'); break;
	case '-': maxv[1][3] = maxv[1][1] - (pan[1][3] - '0');
		minv[1][3] = minv[1][1] - (pan[1][3] - '0'); break;
	}
	switch (pan[2][1]) {
	case '*': maxv[3][1] = maxv[1][1] * (pan[3][1] - '0');
		minv[3][1] = minv[1][1] * (pan[3][1] - '0'); break;
	case '+': maxv[3][1] = maxv[1][1] + (pan[3][1] - '0');
		minv[3][1] = minv[1][1] + (pan[3][1] - '0'); break;
	case '-': maxv[3][1] = maxv[1][1] - (pan[3][1] - '0');
		minv[3][1] = minv[1][1] - (pan[3][1] - '0'); break;
	}
	if (N == 5) {
		switch (pan[1][4]) {
		case '*': maxv[1][5] = maxv[1][3] * (pan[1][5] - '0');
			minv[1][5] = minv[1][3] * (pan[1][5] - '0'); break;
		case '+': maxv[1][5] = maxv[1][3] + (pan[1][5] - '0');
			minv[1][5] = minv[1][3] + (pan[1][5] - '0'); break;
		case '-': maxv[1][5] = maxv[1][3] - (pan[1][5] - '0');
			minv[1][5] = minv[1][3] - (pan[1][5] - '0'); break;
		}
		switch (pan[4][1]) {
		case '*': maxv[5][1] = maxv[3][1] * (pan[5][1] - '0');
			minv[5][1] = minv[3][1] * (pan[5][1] - '0'); break;
		case '+': maxv[5][1] = maxv[3][1] + (pan[5][1] - '0');
			minv[5][1] = minv[3][1] + (pan[5][1] - '0'); break;
		case '-': maxv[5][1] = maxv[3][1] - (pan[5][1] - '0');
			minv[5][1] = minv[3][1] - (pan[5][1] - '0'); break;
		}
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			if (i > 2 && j > 2) {
				switch (pan[i - 1][j]) {
				case '*': temp1 = maxv[i - 2][j] * (pan[i][j] - '0');
					tem1 = minv[i - 2][j] * (pan[i][j] - '0');
					temp2 = maxv[i - 1][j - 1] * (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] * (pan[i][j] - '0'); break;
				case '+': temp1 = maxv[i - 2][j] + (pan[i][j] - '0');
					tem1 = minv[i - 2][j] + (pan[i][j] - '0');
					temp2 = maxv[i - 1][j - 1] + (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] + (pan[i][j] - '0'); break;
				case '-': temp1 = maxv[i - 2][j] - (pan[i][j] - '0');
					tem1 = minv[i - 2][j] - (pan[i][j] - '0');
					temp2 = maxv[i - 1][j - 1] - (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] - (pan[i][j] - '0'); break;
				}
				switch (pan[i][j-1]) {
				case '*': temp3 = maxv[i][j-2] * (pan[i][j] - '0');
					tem3 = minv[i][j-2] * (pan[i][j] - '0');
					temp4 = maxv[i - 1][j - 1] * (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] * (pan[i][j] - '0'); break;
				case '+': temp3 = maxv[i][j - 2] + (pan[i][j] - '0');
					tem3 = minv[i][j - 2] + (pan[i][j] - '0');
					temp4 = maxv[i - 1][j - 1] + (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] + (pan[i][j] - '0'); break;
				case '-': temp3 = maxv[i][j - 2] - (pan[i][j] - '0');
					tem3 = minv[i][j - 2] - (pan[i][j] - '0');
					temp4 = maxv[i - 1][j - 1] - (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] - (pan[i][j] - '0'); break;
				}
				maxv[i][j] = max({ temp1, temp2, temp3, temp4 });
				minv[i][j] = min({ tem1, tem2, tem3, tem4 });
			}
			else if (i == 2 && j == 2) {
				switch (pan[i - 1][j]) {
				case '*':
					temp2 = maxv[i - 1][j - 1] * (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] * (pan[i][j] - '0'); break;
				case '+':
					temp2 = maxv[i - 1][j - 1] + (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] + (pan[i][j] - '0'); break;
				case '-':
					temp2 = maxv[i - 1][j - 1] - (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] - (pan[i][j] - '0'); break;
				}
				switch (pan[i][j - 1]) {
				case '*':
					temp4 = maxv[i - 1][j - 1] * (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] * (pan[i][j] - '0'); break;
				case '+':
					temp4 = maxv[i - 1][j - 1] + (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] + (pan[i][j] - '0'); break;
				case '-':
					temp4 = maxv[i - 1][j - 1] - (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] - (pan[i][j] - '0'); break;
				}
				maxv[i][j] = max({ temp2, temp4 });
				minv[i][j] = min({ tem2, tem4 });
			}
			else if (i == 2 && j > 2) {
				switch (pan[i - 1][j]) {
				case '*':
					temp2 = maxv[i - 1][j - 1] * (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] * (pan[i][j] - '0'); break;
				case '+':
					temp2 = maxv[i - 1][j - 1] + (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] + (pan[i][j] - '0'); break;
				case '-':
					temp2 = maxv[i - 1][j - 1] - (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] - (pan[i][j] - '0'); break;
				}
				switch (pan[i][j - 1]) {
				case '*': temp3 = maxv[i][j - 2] * (pan[i][j] - '0');
					tem3 = minv[i][j - 2] * (pan[i][j] - '0');
					temp4 = maxv[i - 1][j - 1] * (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] * (pan[i][j] - '0'); break;
				case '+': temp3 = maxv[i][j - 2] + (pan[i][j] - '0');
					tem3 = minv[i][j - 2] + (pan[i][j] - '0');
					temp4 = maxv[i - 1][j - 1] + (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] + (pan[i][j] - '0'); break;
				case '-': temp3 = maxv[i][j - 2] - (pan[i][j] - '0');
					tem3 = minv[i][j - 2] - (pan[i][j] - '0');
					temp4 = maxv[i - 1][j - 1] - (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] - (pan[i][j] - '0'); break;
				}
				maxv[i][j] = max({ temp2, temp3, temp4 });
				minv[i][j] = min({ tem2, tem3, tem4 });
			}
			else if (i>2 && j==2){
				switch (pan[i - 1][j]) {
				case '*': temp1 = maxv[i - 2][j] * (pan[i][j] - '0');
					tem1 = minv[i - 2][j] * (pan[i][j] - '0');
					temp2 = maxv[i - 1][j - 1] * (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] * (pan[i][j] - '0'); break;
				case '+': temp1 = maxv[i - 2][j] + (pan[i][j] - '0');
					tem1 = minv[i - 2][j] + (pan[i][j] - '0');
					temp2 = maxv[i - 1][j - 1] + (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] + (pan[i][j] - '0'); break;
				case '-': temp1 = maxv[i - 2][j] - (pan[i][j] - '0');
					tem1 = minv[i - 2][j] - (pan[i][j] - '0');
					temp2 = maxv[i - 1][j - 1] - (pan[i][j] - '0');
					tem2 = minv[i - 1][j - 1] - (pan[i][j] - '0'); break;
				}
				switch (pan[i][j - 1]) {
				case '*':
					temp4 = maxv[i - 1][j - 1] * (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] * (pan[i][j] - '0'); break;
				case '+':
					temp4 = maxv[i - 1][j - 1] + (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] + (pan[i][j] - '0'); break;
				case '-':
					temp4 = maxv[i - 1][j - 1] - (pan[i][j] - '0');
					tem4 = minv[i - 1][j - 1] - (pan[i][j] - '0'); break;
				}
				maxv[i][j] = max({ temp1, temp2, temp4 });
				minv[i][j] = min({ tem1, tem2, tem4 });
			}
		}
	}
	cout << maxv[N][N] << " " << minv[N][N];
}