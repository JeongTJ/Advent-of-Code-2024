#include <bits/stdc++.h>
using namespace std;

// white (w), blue (u), black (b), red (r), or green (g)
// 0 1 2 3 4

// vocab r, wr, b, g, bwu, rb, gb, br

// brwrr
// dp[len] = 이 길이까지 가능한 경우의 수
// dp[0] = 0
// dp[1] = 1
// dp[2] = dp[1] * #r + #br
// dp[1] <- b까지 가능한 경우 수
// dp[2] <- br까지 가능한 경우 수
// dp[3] <- brw까지 가능한 경우 수

map<string, long long> vocab;

long long dp[100000];

void init_vocab() {
	string s;
	while (1) {
		cin >> s;
		if (s == "[sep]")
			break;
		vocab[s] = 1;
	}
}

long long sol(string str) {
	for (int i = 0; i < 100000; i++) dp[i] = 0;
	dp[0] = 1;
	for (int len = 0; len <= str.size(); len++) {
		for (map<string, long long>::iterator it = vocab.begin(); it != vocab.end(); it++) {
			const string &key = it->first;
			if (str.substr(len, key.size()) == key) {
				// if (len == 0) {
				// 	dp[len + key.size()]++;
				// } else if (dp[len] > 0) {
					dp[len + key.size()] += dp[len];
				// }
			}
		}
	}
	cout << "dp: [";
	for (int i = 0; i <= str.size(); i++) {
		cout << dp[i] << ", ";
	}
	cout << "]";
	cout << '\n';
	return dp[str.size()];
}

int main() {
	string s;
	int cnt = 0;

	init_vocab();

	while (cin >> s) {
		long long res = sol(s);
		cout << res << " <- " << s << "\n";
		if (res > 0) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}