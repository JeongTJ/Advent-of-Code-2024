#include <bits/stdc++.h>
using namespace std;

map<int, int> lMap, rMap;

void init_arr() {
	int l, r;
	while (cin >> l >> r) {
		lMap[l]++;
		rMap[r]++;
	}
}

int sol() {
	int res = 0;

	for (map<int, int>::iterator it = lMap.begin(); it != lMap.end(); it++) {
		res += it->second * it->first * rMap[it->first];
	}
	return res;
}

int main() {
	init_arr();
	cout << sol();
	return 0;
}