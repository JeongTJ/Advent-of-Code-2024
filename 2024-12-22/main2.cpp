#include <bits/stdc++.h>
using namespace std;

vector<long long> pwds;
vector<vector<int>> seqs;
vector<vector<int>> bananas;

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
	curr_pwd = curr_pwd ^ temp_pwd;
	curr_pwd = curr_pwd % 16777216;

	temp_pwd = curr_pwd * 2048;
	curr_pwd = curr_pwd ^ temp_pwd;
	curr_pwd = curr_pwd % 16777216;

	return curr_pwd;
}

int main(int argc, char *argv[]) {
	
	init_pwds();
	for (long long &pwd: pwds) {
		vector<int> seq;
		vector<int> banana;
		
		int prev = 0;
		for (int i = 0; i < 2000; i++) {
			banana.push_back(pwd % 10);
			seq.push_back(pwd % 10 - prev);
			prev = pwd % 10;
			pwd = gen_next_pwd(pwd);
		}
		seqs.push_back(seq);
		bananas.push_back(banana);

		// for (int i = 0; i + 4 < 2000; i++) {
		// 	if (seq[i] == -2 && seq[i + 1] == 1 && seq[i + 2] == -1 && seq[i + 3] == 3) {
		// 		// cout << banana[i] << ' ' << seq[i] << '\n';
		// 		// cout << banana[i + 1] << ' ' << seq[i + 1] << '\n';
		// 		// cout << banana[i + 2] << ' ' << seq[i + 2] << '\n';
		// 		// cout << banana[i + 3] << ' ' << seq[i + 3] << '\n';
		// 		res += banana[i + 3];
		// 		break;
		// 	}
		// }

	}

	int ans[4] = {-3, -3, -3, -3};
	long long res = 0;
	int res_ans[4];

	while (!(ans[0] == 3 && ans[1] == 3 && ans[2] == 3 && ans[3] == 3)) {
		long long temp_res = 0;
		for (int idx = 0; idx < bananas.size(); idx++) {
			for (int i = 0; i + 4 < 2000; i++) {
				if (seqs[idx][i] == ans[0] && seqs[idx][i + 1] == ans[1] && seqs[idx][i + 2] == ans[2] && seqs[idx][i + 3] == ans[3]) {
					temp_res += bananas[idx][i + 3];
					break;
				}
			}
		}

		if (res < temp_res) {
			res = temp_res;
			res_ans[0] = ans[0];
			res_ans[1] = ans[1];
			res_ans[2] = ans[2];
			res_ans[3] = ans[3];
			cout << temp_res << "\t\t" << res_ans[0] << ' ' << res_ans[1] << ' ' << res_ans[2] << ' ' << res_ans[3] << '\n';
		}

		ans[3]++;
		for (int i = 3; i > 0; i--) {
			if (ans[i] == 4) {
				ans[i] = -3;
				ans[i - 1]++;
			}
		}
	}

	cout << res << '\n';
	cout << res_ans[0] << ' ' << res_ans[1] << ' ' << res_ans[2] << ' ' << res_ans[3] << '\n';
	return 0;
}