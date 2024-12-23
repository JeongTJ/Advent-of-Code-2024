#include <bits/stdc++.h>
using namespace std;

vector<long long> pwds;

void init_pwds() {
	long long x;

	while (cin >> x) {
		pwds.push_back(x);
	}
}

long long gen_next_pwd(long long curr_pwd) {
	long long temp_pwd;

	temp_pwd = curr_pwd * 64;
	curr_pwd = curr_pwd ^ temp_pwd;
	curr_pwd = curr_pwd % 16777216;

	temp_pwd = curr_pwd / 32;
	// if (curr_pwd % 32 > 16) {
	// 	temp_pwd++;
	// }
	curr_pwd = curr_pwd ^ temp_pwd;
	curr_pwd = curr_pwd % 16777216;

	temp_pwd = curr_pwd * 2048;
	curr_pwd = curr_pwd ^ temp_pwd;
	curr_pwd = curr_pwd % 16777216;

	return curr_pwd;
}

int main(int argc, char *argv[]) {
	long long res = 0;

	init_pwds();
	for (long long &pwd: pwds) {
		for (int i = 0; i < 2000; i++) {
			pwd = gen_next_pwd(pwd);
		}
	}
	for (long long &pwd: pwds) {
		res += pwd;
	}
	cout << res << '\n';
	return 0;
}