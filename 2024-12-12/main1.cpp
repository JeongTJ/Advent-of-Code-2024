#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> arr;
vector<vector<int>> visited;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void init_arr() {
	string s;

	while (!cin.eof()) {
		getline(cin, s);

		vector<char> temp;
		for (char c: s) {
			temp.push_back(c);
		}
		arr.push_back(temp);
	}
}

struct queue_data {
	int y;
	int x;
	char c;
};

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({y, x});
	int fence = 0;
	int cnt = 1;

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			if (!(0 <= next_y && next_y < arr.size() && 0 <= next_x && next_x < arr[0].size())) {
				fence++;
				continue;
			}
			if (arr[next_y][next_x] == arr[cur_y][cur_x] && visited[next_y][next_x]) {
				continue;
			}
			if (arr[next_y][next_x] != arr[cur_y][cur_x] && visited[next_y][next_x]) {
				fence++;
				continue;
			}
			if (arr[next_y][next_x] == arr[cur_y][cur_x]) {
				visited[next_y][next_x] = 1;
				q.push({next_y, next_x});
				cnt++;
			} else {
				fence++;
			}
		}
	}
	return cnt * fence;
}

int main() {
	init_arr();
	visited = vector<vector<int>>(arr.size(), vector<int>(arr[0].size(), 0));
	int res = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (visited[i][j]) continue;
			int tmp = bfs(i, j);
			cout << tmp << '\n';
			res += tmp;
		}
	}
	cout << res << '\n';
	return 0;
}