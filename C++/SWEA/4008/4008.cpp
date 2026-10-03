#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
//#include <cstdio>

using namespace std;

int N;
int maxVal;
int minVal;

int calc(int num1, int num2, int op) {
	switch (op) {
	case 0: return num1 + num2;
	case 1: return num1 - num2;
	case 2: return num1 * num2;
	case 3: return num1 / num2;
	}
	return 0;
}

void dfs(int val, int idx, vector<int>& ops, vector<int>& nums) {
	if (idx == N - 1) {
		maxVal = max(val, maxVal);
		minVal = min(val, minVal);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (ops[i] > 0) {
			--ops[i];
			dfs(calc(val, nums[idx + 1], i), idx+1, ops, nums);
			++ops[i];
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int answer;
		cin >> N;
		vector<int> ops(4);
		vector<int> nums(N);
		for (int i = 0; i < 4; ++i) cin >> ops[i];
		for (int i = 0; i < N; ++i) cin >> nums[i];

		maxVal = -1e9;
		minVal = 1e9;

		dfs(nums[0], 0, ops, nums);

		cout << "#" << test_case << " " << maxVal - minVal << endl;
	}
	return 0;
}