#include <bits/stdc++.h>
using namespace std;

priority_queue<int> lPQ, rPQ;

void init_arr() {
	int l, r;
	while (cin >> l >> r) {
		lPQ.push(l);
		rPQ.push(r);
	}
}

int sol() {
	int res = 0;

	while (!lPQ.empty() && !rPQ.empty()) {
		int l = lPQ.top();
		int r = rPQ.top();
		lPQ.pop();
		rPQ.pop();
		res += (l - r) >= 0 ? l - r : r - l;
	}
	return res;
}

int main() {
	init_arr();
	cout << sol();
	return 0;
}