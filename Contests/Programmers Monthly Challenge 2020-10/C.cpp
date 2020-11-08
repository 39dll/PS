#include <bits/stdc++.h>
using namespace std;
vector<int> edge[280001];
int dis[280001];
int mx = 0, mxind = 0, cnt;
int n, temp1, temp2;
void find(int ind) {
	for (int i = 0; i < edge[ind].size(); i++) {
		int next = edge[ind][i];
		if (dis[next] == -1) {
			dis[next] = dis[ind] + 1;
			if (dis[next] > mx) {
				mx = dis[next];
				mxind = next;
                cnt = 0;
			}
            else if(dis[next] == mx){
                cnt++;
            }
			find(next);
		}
	}
}
int solution(int k, vector<vector<int>> edges) {
    n = k;
    for (int i = 0; i < n - 1; i++) {
		temp1 = edges[i][0];
        temp2 = edges[i][1];
		edge[temp1].push_back(temp2);
		edge[temp2].push_back(temp1);
	}
    for (int i = 1; i <= n; i++) {
		dis[i] = -1;
	}
    dis[1] = 0;
	find(1);
	for (int i = 1; i <= n; i++) {
		dis[i] = -1;
	}
	mx = 0;
	dis[mxind] = 0;
    cnt = 0;
	find(mxind);
    if(cnt<=0){
	    return mx - 1;
    }
    if(cnt>=1){
        return mx;
    }
}
