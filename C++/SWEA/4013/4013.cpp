#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <cmath>

using namespace std;

void move(vector<int>& magnetic, int dir) {
	if (dir == 1) {
		int tmp = magnetic[7];
		for (int i = 7; i > 0; --i)
			magnetic[i] = magnetic[i-1];
		magnetic[0] = tmp;
	}
	else if (dir == -1) {
		int tmp = magnetic[0];
		for (int i = 0; i < 7 ; ++i)
			magnetic[i] = magnetic[i + 1];
		magnetic[7] = tmp;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input_4013.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int K;
		cin >> K;
		int score = 0;

		vector<vector<int>> magnetics(4, vector<int>(8));
		vector<int> num(K);
		vector<int> dir(K);
		

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 8; ++j) cin >> magnetics[i][j];
		}
		for (int i = 0; i < K; ++i)
			cin >> num[i] >> dir[i];

		for (int i = 0; i < K; ++i) {
			vector<int> rotate(4, 0);
			int idx = num[i] - 1;
			rotate[idx] = dir[i];
			for (int left = idx - 1; left >= 0; --left) {
				int cur = left + 1;
				if (magnetics[left][2] != magnetics[cur][6])
					rotate[left] = rotate[cur] * -1;
				else break;
			}
			for (int right = idx + 1; right < 4; ++right) {
				int cur = right - 1;
				if (magnetics[right][6] != magnetics[cur][2])
					rotate[right] = rotate[cur] * -1;
				else break;
			}
			for (int i = 0; i < 4; ++i) {
				move(magnetics[i], rotate[i]);
			}
		}
		
		for (int i = 0; i < 4; ++i) {
			if (magnetics[i][0] == 1) score += pow(2, i);
		}
		cout << "#" << test_case << " " << score << endl;
	}
	return 0;
}