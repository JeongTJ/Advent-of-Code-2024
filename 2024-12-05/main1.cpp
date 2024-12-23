#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> reference_arr;
vector<int> origin_reference_arr;

int arr[100][100];

void init_tree() {
	int parent, child;
	char or_char;

	tree.resize(105);
	reference_arr.resize(105);
	origin_reference_arr.resize(105);

	while (1) {
		cin >> parent >> or_char >> child;
		if (parent == -1 && child == -1) {
			break;
		}
		arr[parent][child] = 1;
		// cout << "parent: " << parent << " " << "child: " << child << '\n';
		tree[parent].push_back(child);
		reference_arr[child]++;
	}
	origin_reference_arr = reference_arr;
}

void sol() {
	string s;
	int res = 0;

	getline(cin, s);
	while (!cin.eof()) {
		getline(cin, s);

		istringstream iss(s);
		int task;
		char c;
		bool is_right = true;
		vector<int> temp;
		while (iss >> task) {
			iss >> c;
			temp.push_back(task);
		}
		for (int i = 0; i < temp.size(); i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				if (arr[temp[j]][temp[i]]) {
					is_right = false;
				}
			}
		}
		if (is_right) {
			res += temp[temp.size() / 2];
		}
	}
	cout << res << '\n';
}

int main() {
	init_tree();
	sol();
	return 0;
}