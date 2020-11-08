#include <bits/stdc++.h>
using namespace std;
int N, white = 0, blue = 0, depth = 0;
bool a[1025][1025];
char temp[65];
int cnt, cnt2;
void search(int depth, int startx, int starty) {
	int w, wt = 0, bl = 0;
	w = N / pow(2, depth);
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i + startx][j + starty] == 1) bl++;
			else wt++;
		}
	}
	if (wt == w*w) {
		//cout << "0";
		cnt++;
		return;
	}
	else if (bl == w*w) {
		cnt2++;
		//cout << "1";
		return;
	}
	search(depth + 1, startx, starty);
	search(depth + 1, startx, starty + w / 2);
	search(depth + 1, startx + w / 2, starty);
	search(depth + 1, startx + w / 2, starty + w / 2);
}
vector<int> solution(vector<vector<int>> arr) {
    N = arr[0].size();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a[i][j]=arr[i][j];
        }
    }
    search(0, 0, 0);
	return {cnt, cnt2};
}
