#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

using namespace std;

struct BC {
	int col, row;
	int c;
	int p;
};

bool isPossible(int x, int y, int tx, int ty, int c) {
	if (abs(tx - x) + abs(ty - y) <= c) return true;
	return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input_5644.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int m, a;
		cin >> m >> a;
		vector<int> A(m);
		vector<int> B(m);
		for (int i = 0; i < m; ++i) cin >> A[i];
		for (int i = 0; i < m; ++i) cin >> B[i];
		vector<BC> bc(a);
		for (int i = 0; i < a; ++i) cin >> bc[i].col >> bc[i].row >> bc[i].c >> bc[i].p;
		int answer = 0;;
		int aC = 1, aR = 1;
		int bC = 10, bR = 10;

		int dr[5] = { 0,-1,0,1,0 };
		int dc[5] = { 0,0,1,0,-1 };

		for (int time = 0; time <= m; ++time) {
			vector<vector<bool>> isCharge(a, vector<bool>(2, false));
			if (time > 0) {
				aR += dr[A[time-1]];
				aC += dc[A[time-1]];
				bR += dr[B[time-1]];
				bC += dc[B[time-1]];
			}
			for (int i = 0; i < a; ++i) {
				if (isPossible(bc[i].col, bc[i].row, aC, aR, bc[i].c)) isCharge[i][0] = true;
				if (isPossible(bc[i].col, bc[i].row, bC, bR, bc[i].c)) isCharge[i][1] = true;
			}
			
			int maxCharge = 0;
			for (int i = -1; i < a; ++i) {
				if (i != -1 && !isCharge[i][0]) continue;
				for (int j = -1; j < a; ++j) {
					if (j != -1 && !isCharge[j][1]) continue;
					int charge = 0;
					if (i != -1 && i == j) {
						charge += bc[i].p;
					}
					else {
						if (i != -1) charge += bc[i].p;
						if (j != -1) charge += bc[j].p;
					}
					maxCharge = max(charge, maxCharge);
				}
			}
			answer += maxCharge;
		}
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}