#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

int N;
vector<vector<int>> answer;

tuple<int,int,int> move(int r, int c, int dir, vector<vector<int>>& graph) {
	vector<vector<int>> turn = { {1,2,3,4}, { 3,4,2,1 },{4,3,1,2},{2,1,4,3} };
	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };

	graph[r][c] = -1;

	while (true) {
		bool moved = false;
		for (int i = 0; i < 4; ++i) {
			int curDir = turn[i][dir - 1];
			int nr = r + dr[curDir-1];
			int nc = c + dc[curDir-1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (graph[nr][nc] == 1 || graph[nr][nc] == -1) continue;
			
			r = nr;
			c = nc;
			dir = curDir;
			graph[nr][nc] = -1;
			moved = true;
			answer.push_back({ nr+1,nc+1 });
			break;
		}
		if (!moved) return { r,c,dir };

	}
	return { r,c,dir };
}

pair<int, int> bfs(int r, int c, vector<vector<int>>& graph) {
	vector<int> turn = { 3,2,4,1 };
	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	queue<tuple<int, int, int>> q;
	q.push({ r,c,0 });
	visited[r][c] = true;
	tuple<int, int, int> best = {51*51, 50, 50};
	while (!q.empty()) {
		auto [row, col, dist] = q.front();
		q.pop();
		if (dist > get<0>(best)) break;
		if (graph[row][col] == 0) {
			best = min(best, make_tuple(dist, row, col));
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			int curDir = turn[i];
			int nr = row + dr[curDir - 1];
			int nc = col + dc[curDir - 1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (graph[nr][nc] == 1 || visited[nr][nc]) continue;
			visited[nr][nc] = true;
			q.push({ nr,nc,dist + 1 });
		}
	}
	if (get<0>(best) == 51 * 51) return { -1,-1 };
	return { get<1>(best), get<2>(best) };
}

vector<vector<int>> getDist(int r, int c, vector<vector<int>>& graph) {
	queue<pair<int, int>> q;
	vector<vector<int>> dist(N, vector<int>(N, -1));
	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };

	q.push({ r,c });
	dist[r][c] = 0;
	while (!q.empty()) {
		auto [row, col] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = row + dr[i];
			int nc = col + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (dist[nr][nc] != -1 || graph[nr][nc] == 1) continue;
			dist[nr][nc] = dist[row][col] + 1;
			q.push({ nr, nc });
		}
	}
	return dist;
}

int main() {
	int r, c, d;
	cin >> N >> r >> c >> d;
	vector<vector<int>> map(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> map[i][j];
	}

	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };
	int turn[4] = { 3,2,4,1 };

	--r;
	--c;
	answer.push_back({ r+1, c+1 });
	while (true) {
		auto [row, col, dir] = move(r, c, d, map);
		auto [tr, tc] = bfs(row, col, map);
		if (tr == -1) break;
		vector<vector<int>> dist = getDist(tr, tc, map);
		
		while (row != tr || col != tc) {
			for (int i = 0; i < 4; ++i) {
				int curDir = turn[i];
				int nr = row + dr[curDir - 1];
				int nc = col + dc[curDir - 1];
				if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				if (dist[nr][nc] != dist[row][col] - 1) continue;
				row = nr;
				col = nc;
				dir = curDir;
				if (map[row][col] == 0) {
					map[row][col] = -1;
					answer.push_back({ row + 1, col + 1 });
				}
				break;
			}
		}
		r = row;
		c = col;
		d = dir;
	}

	for (vector<int> a : answer) {
		cout << a[0] << " " << a[1] << endl;
	}

	return 0;
}