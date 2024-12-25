#include <bits/stdc++.h>
using namespace std;

map<long long, long long> m;

void init_m() {
	long long stone;

	while (!cin.eof()) {
		cin >> stone;
		m[stone] = 1;
	}
}

pair<long long, long long> split_stone(long long stone) {
	string s = to_string(stone);

	if (stone == 0) {
		return {1, -1};
	}
	if (s.size() > 0 && s.size() % 2 == 0) {
		string sl, sr;
		sl = s.substr(0, s.size() / 2);
		sr = s.substr(s.size() / 2, s.size() / 2);
		return {stol(sl), stol(sr)};
	} else {
		return {stone * 2024, -1};
	}
	return {-1, -1};
}

void blink() {
	map<long long, long long> temp;
	for (map<long long, long long>::iterator it = m.begin(); it != m.end(); it++) {
		pair<long long, long long> stones = split_stone(it->first);
		if (stones.first != -1) {
			temp[stones.first] += it->second;
		}
		if (stones.second != -1) {
			temp[stones.second] += it->second;
		}
		it->second = 0;
	}
	for (map<long long, long long>::iterator it = temp.begin(); it != temp.end(); it++) {
		m[it->first] = it->second;
	}
}

int main() {
	init_m();
	for (int i = 0; i < 75; i++) {
		blink();
	}
	long long res = 0;
	for (map<long long, long long>::iterator it = m.begin(); it != m.end(); it++) {
		res += it->second;
	}
	cout << res << '\n';
	return 0;
}