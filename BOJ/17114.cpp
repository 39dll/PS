#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
int m, n, o, p, q, r, s, t, u, v, w;
int res = 0, temp;
int zm[22] = { 1,-1, };
int zn[22] = { 0,0,1,-1, };
int zo[22] = { 0,0,0,0,1,-1, };
int zp[22] = { 0,0,0,0,0,0,1,-1, };
int zq[22] = { 0,0,0,0,0,0,0,0,1,-1, };
int zr[22] = { 0,0,0,0,0,0,0,0,0,0,1,-1, };
int zs[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,1,-1, };
int zt[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1, };
int zu[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1, };
int zv[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1, };
int zw[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1 };
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;
	queue<tuple<int, int, int, int, int, int, int, int, int, int, int> > qu;
	int ***********tom;
	int ***********st;
	tom = new int**********[m];
	st = new int**********[m];
	for (int a = 0; a < m; a++) {
		*(tom + a) = new int*********[n];
		*(st + a) = new int*********[n];
		for (int b = 0; b < n; b++) {
			*(*(tom + a) + b) = new int********[o];
			*(*(st + a) + b) = new int********[o];
			for (int c = 0; c < o; c++) {
				*(*(*(tom + a) + b) + c) = new int*******[p];
				*(*(*(st + a) + b) + c) = new int*******[p];
				for (int d = 0; d < p; d++) {
					*(*(*(*(tom + a) + b) + c) + d) = new int******[q];
					*(*(*(*(st + a) + b) + c) + d) = new int******[q];
					for (int e = 0; e < q; e++) {
						*(*(*(*(*(tom + a) + b) + c) + d) + e) = new int*****[r];
						*(*(*(*(*(st + a) + b) + c) + d) + e) = new int*****[r];
						for (int f = 0; f < r; f++) {
							*(*(*(*(*(*(tom + a) + b) + c) + d) + e) + f) = new int****[s];
							*(*(*(*(*(*(st + a) + b) + c) + d) + e) + f) = new int****[s];
							for (int g = 0; g < s; g++) {
								*(*(*(*(*(*(*(tom + a) + b) + c) + d) + e) + f) + g) = new int***[t];
								*(*(*(*(*(*(*(st + a) + b) + c) + d) + e) + f) + g) = new int***[t];
								for (int h = 0; h < t; h++) {
									*(*(*(*(*(*(*(*(tom + a) + b) + c) + d) + e) + f) + g) + h) = new int**[u];
									*(*(*(*(*(*(*(*(st + a) + b) + c) + d) + e) + f) + g) + h) = new int**[u];
									for (int i = 0; i < u; i++) {
										*(*(*(*(*(*(*(*(*(tom + a) + b) + c) + d) + e) + f) + g) + h) + i) = new int*[v];
										*(*(*(*(*(*(*(*(*(st + a) + b) + c) + d) + e) + f) + g) + h) + i) = new int*[v];
										for (int j = 0; j < v; j++) {
											*(*(*(*(*(*(*(*(*(*(tom + a) + b) + c) + d) + e) + f) + g) + h) + i) + j) = new int[w];
											*(*(*(*(*(*(*(*(*(*(st + a) + b) + c) + d) + e) + f) + g) + h) + i) + j) = new int[w];
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int a = 0; a < w; a++) {
		for (int b = 0; b < v; b++) {
			for (int c = 0; c < u; c++) {
				for (int d = 0; d < t; d++) {
					for (int e = 0; e < s; e++) {
						for (int f = 0; f < r; f++) {
							for (int g = 0; g < q; g++) {
								for (int h = 0; h < p; h++) {
									for (int i = 0; i < o; i++) {
										for (int j = 0; j < n; j++) {
											for (int k = 0; k < m; k++) {
												cin >> temp;
												st[a][b][c][d][e][f][g][h][i][j][k] = 0;
												tom[a][b][c][d][e][f][g][h][i][j][k] = temp;
												if (temp == 1) {
													st[a][b][c][d][e][f][g][h][i][j][k] = 1;
													qu.push(make_tuple(a, b, c, d, e, f, g, h, i, j, k));
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	while (!qu.empty()) {
		int m = get<0>(qu.front());
		int n = get<1>(qu.front());
		int o = get<2>(qu.front());
		int p = get<3>(qu.front());
		int q = get<4>(qu.front());
		int r = get<5>(qu.front());
		int s = get<6>(qu.front());
		int t = get<7>(qu.front());
		int u = get<8>(qu.front());
		int v = get<9>(qu.front());
		int w = get<10>(qu.front());
		qu.pop();
		for (int i = 0; i <= 21; i++) {
			int nm = m + zm[i];
			int nn = n + zn[i];
			int no = o + zo[i];
			int np = p + zp[i];
			int nq = q + zq[i];
			int nr = r + zr[i];
			int ns = s + zs[i];
			int nt = t + zt[i];
			int nu = u + zu[i];
			int nv = v + zv[i];
			int nw = w + zw[i];
			if (nm >= 0 && nm < m &&
				nn >= 0 && nn < n &&
				no >= 0 && no < o &&
				np >= 0 && np < p &&
				nq >= 0 && nq < q &&
				nr >= 0 && nr < r &&
				ns >= 0 && ns < s &&
				nt >= 0 && nt < t &&
				nu >= 0 && nu < u &&
				nv >= 0 && nv < v &&
				nw >= 0 && nw < w) {
				if (st[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] == 0 &&
					tom[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] == 0) {
					st[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] =
						st[m][n][o][p][q][r][s][t][u][v][w] + 1;
					qu.push(make_tuple(nm, nn, no, np, nq, nr, ns, nt, nu, nv, nw));
				}
			}
		}
	}
	for (int a = 0; a < w; a++) {
		for (int b = 0; b < v; b++) {
			for (int c = 0; c < u; c++) {
				for (int d = 0; d < t; d++) {
					for (int e = 0; e < s; e++) {
						for (int f = 0; f < r; f++) {
							for (int g = 0; g < q; g++) {
								for (int h = 0; h < p; h++) {
									for (int i = 0; i < o; i++) {
										for (int j = 0; j < n; j++) {
											for (int k = 0; k < m; k++) {
												res = max(res, st[a][b][c][d][e][f][g][h][i][j][k]);
												if (tom[a][b][c][d][e][f][g][h][i][j][k] == 0 &&
													st[a][b][c][d][e][f][g][h][i][j][k] == 0){
													cout << "-1";
													return 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << res - 1;
}
