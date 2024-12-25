#include <bits/stdc++.h>
using namespace std;

list<pair<int, int>> slots;

void init_arr() {
	char c;
	bool flag = true;
	int num = 0;

	while (!cin.eof()) {
		cin >> c;
		if (flag) {
			slots.push_back({num, c - '0'});
		} else {
			slots.push_back({-1, c - '0'});
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
	list<pair<int, int>>::iterator last_slot = --slots.end();
	list<pair<int, int>>::iterator empty_slot = slots.begin();

	while (last_slot != slots.begin()) {
		if (last_slot->first != -1) {
			empty_slot = slots.begin();
			while (1) {
				// cout << empty_slot->first << '\n';
				if (empty_slot == last_slot) break;
				if (empty_slot->first == -1 &&empty_slot->second >= last_slot->second) break;

				empty_slot++;
			}
			if (empty_slot != last_slot) {
				empty_slot->second -= last_slot->second;
				slots.insert(empty_slot, {last_slot->first, last_slot->second});
				last_slot->first = -1;
				// for (list<pair<int, int>>::iterator it = slots.begin(); it != slots.end(); it++) {
				// 	for (int i = 0; i < it->second; i++) {
				// 		if (it->first == -1){
				// 			cout << '.';
				// 		} else {
				// 			cout << it->first;
				// 		}
				// 	}
				// }
				// cout << '\n';
			}
		}
		last_slot--;
	}
}

long long get_res() {
	long long res = 0;
	long long idx = 0;
	for (list<pair<int, int>>::iterator it = slots.begin(); it != slots.end(); it++) {
		for (int i = 0; i < it->second; i++) {
			if (it->first != -1){
				res += idx * it->first;
			}
			idx++;
		}
	}
	return res;
}

int main() {
	init_arr();
	for (list<pair<int, int>>::iterator it = slots.begin(); it != slots.end(); it++) {
		for (int i = 0; i < it->second; i++) {
			if (it->first == -1){
				cout << '.';
			} else {
				cout << it->first;
			}
		}
	}
	cout << '\n';
	fill_empty_arr();
	cout << get_res() << '\n';
	return 0;
}