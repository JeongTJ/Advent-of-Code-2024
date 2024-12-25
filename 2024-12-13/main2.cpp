#include <bits/stdc++.h>
using namespace std;

struct Button {
	long long x;
	long long y;
};

struct vec_data {
	Button button1;
	Button button2;
	Button target;
};

vector<vec_data> v;

void init_v() {
	string s;
	vec_data vd;
	while (!cin.eof()) {
		getline(cin, s);
		istringstream iss(s);

		while (!iss.eof()) {
			string button, name, x, y;
			iss >> button >> name >> x >> y;
			if (button == "Button") {
				x = x.substr(0, x.size() - 1);
				if (name == "A:") {
					vd.button1.x = stol(x.substr(2));
					vd.button1.y = stol(y.substr(2));
				} else if (name == "B:") {
					vd.button2.x = stol(x.substr(2));
					vd.button2.y = stol(y.substr(2));
				}
			} else if (button == "Prize:") {
				y = x;
				x = name;
				x = x.substr(0, x.size() - 1);
				vd.target.x = stol(x.substr(2)) + 10000000000000;
				vd.target.y = stol(y.substr(2)) + 10000000000000;
				// vd.target.x = stol(x.substr(2));
				// vd.target.y = stol(y.substr(2));

				v.push_back(vd);
			}
		}
	}
}

/*
[a b]
[c d]

[d, -b]
[-c, a]



*/

int main() {
	init_v();
	long long total = 0;
	for (int i = 0; i < v.size(); i++) {
		long long a, b, c, d, adbc, target_x, target_y;
		a = v[i].button1.x;
		b = v[i].button2.x;
		c = v[i].button1.y;
		d = v[i].button2.y;
		target_x = v[i].target.x;
		target_y = v[i].target.y;
		// [ x1 x2 ] = [a b] * [res_a] = [target_x]
		// [ y1 y2 ] = [c d] * [res_b] = [target_y]
		
		adbc = a * d - b * c;
		long long res_a, res_b;

		res_a = target_x * d - target_y * b;
		res_b = target_y * a - target_x * c;
		res_a /= adbc;
		res_b /= adbc;
		cout << "target_x: " << target_x << '\n';
		cout << "target_y: " << target_y << '\n';
		cout << "res_a: " << res_a << '\n';
		cout << "res_b: " << res_b << '\n';
		if (res_a * a + res_b * b == target_x && res_a * c + res_b * d == target_y) {
			total += res_a * 3 + res_b;
		}
	}
	cout << total << '\n';
	return 0;
}