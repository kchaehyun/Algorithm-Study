#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

using namespace std;

struct Microbe {
	int r, c;
	int cnt;
	int dir;
};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input_2382.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M, K;
		int answer = 0;

		cin >> N >> M >> K;
		vector<Microbe> microbe(K);
		int dr[4] = { -1,1,0,0 };
		int dc[4] = { 0,0,-1,1 };
		vector<int> opposite = { 2,1,4,3 };

		for (int i = 0; i < K; ++i) {
			cin >> microbe[i].r >> microbe[i].c >> microbe[i].cnt >> microbe[i].dir;
		}

		for (int time = 0; time < M; ++time) {
			vector<vector<int>> pos(N, vector<int>(N, -1));
			vector<vector<int>> maxCnt(N, vector<int>(N, 0));
			for (int i = 0; i < K; ++i) {
				if (!microbe[i].cnt) continue;
				microbe[i].r += dr[microbe[i].dir - 1];
				microbe[i].c += dc[microbe[i].dir - 1];
				if (microbe[i].r == 0 || microbe[i].r == N - 1 || microbe[i].c == 0 || microbe[i].c == N - 1) {
					microbe[i].cnt /= 2;
					microbe[i].dir = opposite[microbe[i].dir - 1];
					if (!microbe[i].cnt) continue;
				}
				if (pos[microbe[i].r][microbe[i].c] != -1) {
					int j = pos[microbe[i].r][microbe[i].c];
					if (maxCnt[microbe[i].r][microbe[i].c] < microbe[i].cnt) {
						maxCnt[microbe[i].r][microbe[i].c] = microbe[i].cnt;
						microbe[j].dir = microbe[i].dir;
					}
					microbe[j].cnt += microbe[i].cnt;
					microbe[i].cnt = 0;
				}
				else if (pos[microbe[i].r][microbe[i].c] == -1) {
					pos[microbe[i].r][microbe[i].c] = i;
					maxCnt[microbe[i].r][microbe[i].c] = microbe[i].cnt;
				}
			}
		}
		for (int i = 0; i < K; ++i) answer += microbe[i].cnt;

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}