#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
// #include <cstdio>

using namespace std;

int answer = 0;

void dfs(int month, int cost, vector<int>& months, vector<int>& costs) {
	if (cost > answer) return;
	if (month > 11) {
		answer = min(answer, cost);
		return;
	}
	if (!months[month]) {
		dfs(month + 1, cost + months[month] * costs[0], months, costs);
		return;
	}
	int oneMonth = min(cost + months[month] * costs[0], cost + costs[1]);
	dfs(month + 1, oneMonth, months, costs);
	dfs(month + 3, cost + costs[2], months, costs);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	// freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> costs(4);
		vector<int> months(15);
		for (int i = 0; i < 4; ++i) cin >> costs[i];
		for (int i = 0; i < 12; ++i) cin >> months[i];
		answer = costs[3];
		
		dfs(0, 0, months, costs);


		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}