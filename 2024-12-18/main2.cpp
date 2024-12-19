#include <bits/stdc++.h>
using namespace std;

int arr[71][71];
int visited[71][71];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int s_x, int s_y) {
	queue<tuple<int, int, int>> q;
	memset(visited, 0, sizeof(visited));
	q.push({s_x, s_y, 0});
	visited[s_x][s_y] = 1;

	while (!q.empty()) {
		int cur_x = get<0>(q.front());
		int cur_y = get<1>(q.front());
		int cur_cnt = get<2>(q.front());

		q.pop();

		if (cur_x == 70 && cur_y == 70) {
			return cur_cnt;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (!(0 <= next_y && next_y < 71 && 0 <= next_x && next_x < 71)) continue;
			if (visited[next_x][next_y]) continue;
			if (arr[next_x][next_y] == 1) continue;
			visited[next_x][next_y] = 1;
			q.push({next_x, next_y, cur_cnt + 1});
		}
	}
	return -1;
}

void init_arr() {
	int x, y;
	char temp;

	while (cin >> x >> temp >> y) {
		arr[x][y] = 1;
		if (bfs(0, 0) == -1) {
			cout << x << ',' << y << '\n';
			return ;
		}
		system("clear");
		for (int i = 0; i < 70; i++) {
			for (int j = 0; j < 70; j++) {
				if (arr[j][i] == 0)
					cout << '.';
				else
					cout << '#';
			}
			cout << '\n';
		}
	}
}

int main() {
	init_arr();
	return 0;
}