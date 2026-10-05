#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

using namespace std;

int N;
int answer;

void dfs(int start, int cnt, const vector<vector<int>>& s, vector<bool>& selected) {
	if (cnt == N / 2) {
		int A = 0, B = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = i+1; j < N; ++j) {
				if (selected[i] && selected[j]) {
					A += s[i][j] + s[j][i];
				}
				else if (!selected[i] && !selected[j]) {
					B += s[i][j] + s[j][i];
				}
			}
		}
		answer = min(answer, abs(A - B));
		return;
	}
	for (int i = start; i < N; ++i) {
		selected[i] = true;
		dfs(i + 1, cnt + 1, s, selected);
		selected[i] = false;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input_4012.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		answer = 20000;
		cin >> N;
		vector<vector<int>> s(N, vector<int>(N));
		vector<bool> selected(N, false);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> s[i][j];
			}
		}

		dfs(0, 0, s, selected);
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}