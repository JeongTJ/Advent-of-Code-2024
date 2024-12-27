#include <bits/stdc++.h>
using namespace std;

long long A;
long long B;
long long C;

long long registers[7] = {0, 1, 2, 3, 0, 0, 0};

vector<int> instruction;
int pointer = 0;

void init_instruction() {
	string s;
	char c;
	long long num;

	cin >> s >> s >> num;
	registers[4] = num;
	cin >> s >> s >> num;
	registers[5] = num;
	cin >> s >> s >> num;
	registers[6] = num;

	cin >> s;
	while (1) {
		cin >> num;
		instruction.push_back(num);
		cin >> c;
		if (cin.eof()) break;
	}
}

void adv(int opcode, int operand) {
	if (opcode != 0) return ;
	long long &A = registers[4];

	A = A >> registers[operand];
	pointer += 2;
}

void bxl(int opcode, int operand) {
	if (opcode != 1) return ;
	long long &B = registers[5];

	B ^= operand;
	pointer += 2;
}

void bst(int opcode, int operand) {
	if (opcode != 2) return ;
	long long &B = registers[5];

	B = registers[operand] % 8;
	pointer += 2;
}

void jnz(int opcode, int operand) {
	if (opcode != 3) return ;
	long long &A = registers[4];

	if (A == 0) {
		pointer += 2;
		return ;
	}
	pointer = operand;
}

void bxc(int opcode, int operand) {
	if (opcode != 4) return ;
	long long &B = registers[5];
	long long &C = registers[6];

	B = B ^ C;
	pointer += 2;
}

void out(int opcode, int operand) {
	if (opcode != 5) return ;
	cout << registers[operand] % 8 << ',';
	pointer += 2;
}

void bdv(int opcode, int operand) {
	if (opcode != 6) return ;
	long long &A = registers[4];
	long long &B = registers[5];

	B = A >> registers[operand];
	pointer += 2;
}

void cdv(int opcode, int operand) {
	if (opcode != 7) return ;
	long long &A = registers[4];
	long long &C = registers[6];

	C = A >> registers[operand];
	pointer += 2;
}

void run_instruction(int opcode, int operand) {
	// cout << "opcode: " << opcode << " operand: " << operand << '\n';
	switch (opcode) {
	case 0:
		adv(opcode, operand);
		break;
	case 1:
		bxl(opcode, operand);
		break;
	case 2:
		bst(opcode, operand);
		break;
	case 3:
		jnz(opcode, operand);
		break;
	case 4:
		bxc(opcode, operand);
		break;
	case 5:
		out(opcode, operand);
		break;
	case 6:
		bdv(opcode, operand);
		break;
	case 7:
		cdv(opcode, operand);
		break;
	}
}

int main() {
	init_instruction();
	// cout << instruction.size();
	while (pointer < instruction.size()) {
		// cout << "A: " << registers[4] << '\n';
		// cout << "B: " << registers[5] << '\n';
		// cout << "C: " << registers[6] << '\n';
		// cout << '\n';
		// for (int i = 0; i < 7; i++) {
		// 	cout << "r[" << i << "]: " << registers[i] << ' ';
		// }
		// cout << '\n';
		run_instruction(instruction[pointer], instruction[pointer + 1]);
	}
	return 0;
}