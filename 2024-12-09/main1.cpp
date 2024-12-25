#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

void init_arr() {
	char c;
	bool flag = true;
	int num = 0;

	while (!cin.eof()) {
		cin >> c;
		for (int i = 0; i < c - '0'; i++) {
			if (flag) {
				arr.push_back(num);
			} else {
				arr.push_back(-1);
			}
		}
		if (flag) {
			num++;
			flag = false;
		} else {
			flag = true;
		}
	}
}

void fill_empty_arr() {
	int ridx = arr.size() - 1;
	int idx = 0;

	while (ridx > idx) {
		if (arr[ridx] == -1) {
			ridx--;
		} else if (arr[ridx] != -1) {
			while (arr[idx] != -1) {
				idx++;
			}
			if (!(ridx > idx)) {
				break;
			}
			arr[idx] = arr[ridx];
			arr[ridx] = -1;
		}
	}
}

long long get_res() {
	long long res = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == -1) break;
		res += i * arr[i];
	}
	return res;
}

int main() {
	init_arr();
	fill_empty_arr();
	cout << get_res() << '\n';
	return 0;
}