#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> arr;
vector<vector<int>> visited;
int player_x, player_y;
int end_x, end_y;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void init_arr() {
	string s;

	while (!cin.eof()) {
		getline(cin, s);
		vector<char> tmp;
		for (char c: s) {
			tmp.push_back(c);
		}
		arr.push_back(tmp);
	}
	visited = vector<vector<int>>(arr.size(), vector<int>(arr[0].size(), 987654321));
}

void find_player() {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 'S') {
				player_y = i;
				player_x = j;
			}
			if (arr[i][j] == 'E') {
				end_y = i;
				end_x = j;
			}
		}
	}
}

struct queue_data {
	int y;
	int x;
	int dir;
	int score;
};

int dfs(int y, int x, int dir, int score) {
	if (arr[y][x] == 'E') { 
		return score;
	}
	int res = 987654321;
	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		if (arr[next_y][next_x] == '#') continue;
		if (visited[next_y][next_x]) continue;
		visited[next_y][next_x] = 1;
		if (dir == i || dir == -1) {
			res = min(res, dfs(next_y, next_x, i, score + 1));
		} else {
			res = min(res, dfs(next_y, next_x, i, score + 1001));
		}
		visited[next_y][next_x] = 0;
	}
	return res;
}

void bfs() {
	queue<queue_data> q;
	q.push({player_y, player_x, -1, 3});
	visited[q.front().y][q.front().x] = q.front().score;

	while (!q.empty()) {
		queue_data cur = q.front();
		q.pop();

		if (arr[cur.y][cur.x] == 'E') {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = cur.y + dy[i];
			int next_x = cur.x + dx[i];
			int next_score;
			if (cur.dir == i || cur.dir == -1) {
				next_score = cur.score + 1;
			} else {
				next_score = cur.score + 1001;
			}

			if (arr[next_y][next_x] == '#') continue;
			if (visited[next_y][next_x] < cur.score) continue;
			visited[next_y][next_x] = next_score;
			q.push({next_y, next_x, i, next_score});
		}
	}
}

int main() {
	init_arr();
	find_player();
	bfs();
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (visited[i][j] == 987654321) {
				cout << " ...... ";
			} else {
				cout << setw(7) << visited[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	cout << visited[end_y][end_x] << '\n';
	return 0;
}