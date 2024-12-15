#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

#define WIDTH 101
#define HEIGHT 103
// #define WIDTH 11
// #define HEIGHT 7

int arr[HEIGHT][WIDTH];

class Dots {
	public:
		Dots(): y(0), x(0), v_y(0), v_x(0), cnt(0) { }
		Dots(int y, int x, int v_y, int v_x): y(y), x(x), v_y(v_y), v_x(v_x), cnt(1) { }
		
		void move() {
			this->y = (this->y + this->v_y + HEIGHT) % HEIGHT;
			this->x = (this->x + this->v_x + WIDTH) % WIDTH;
		}

		void reverse_move() {
			this->y = (this->y - this->v_y + HEIGHT) % HEIGHT;
			this->x = (this->x - this->v_x + WIDTH) % WIDTH;
		}

		void increaseCnt() {
			this->cnt++;
		}

		int getCnt() const { return this->cnt; }
		int getY() const { return this->y; }
		int getX() const { return this->x; }

	private:
		int y, x;
		int v_y, v_x;
		int cnt;
};

bool check_same_pos(int y, int x, vector<Dots> &dotsContainer) {
	for (Dots &item: dotsContainer) {
		if (item.getY() == y && item.getX() == x) {
			item.increaseCnt();
			return true;
		}
	}
	return false;
}

int return_ans(vector<Dots> &dotsContainer) {
	int lu, ru, ld, rd;

	lu = ru = ld = rd = 0;
	for (Dots &item: dotsContainer) {
		if (0 <= item.getY() && item.getY() < HEIGHT / 2 && 0 <= item.getX() && item.getX() < WIDTH / 2)
			lu += item.getCnt();
		if (HEIGHT / 2 < item.getY() && item.getY() < HEIGHT && 0 <= item.getX() && item.getX() < WIDTH / 2)
			ld += item.getCnt();
		if (0 <= item.getY() && item.getY() < HEIGHT / 2 && WIDTH / 2 < item.getX() && item.getX() < WIDTH)
			ru += item.getCnt();
		if (HEIGHT / 2 < item.getY() && item.getY() < HEIGHT && WIDTH / 2 < item.getX() && item.getX() < WIDTH)
			rd += item.getCnt();
	}
	return lu * ld * ru * rd;
}

void print_arr(vector<Dots> &dotsContainer) {
	cout << "==== print ====\n";
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			arr[i][j] = 0;
		}
	}
	for (Dots &item: dotsContainer) {
		arr[item.getY()][item.getX()] = item.getCnt();
	}
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (arr[i][j] == 0)
				cout << '.';
			else
				cout << arr[i][j];
		}
		cout << '\n';
	}
}

void print_sfml(vector<Dots> &dotsContainer) {
	sf::RenderWindow window(sf::VideoMode(WIDTH * 10 + 100, HEIGHT * 10 + 100), "SFML Window");

	sf::Font font;

	if (!font.loadFromFile("./font/BMDOHYEON_ttf.ttf")) {
		// 폰트 로드 실패 처리
		return ;
	}
	sf::Text text;

	text.setPosition(sf::Vector2f(WIDTH - 100, 0));
	text.setScale(sf::Vector2f(0.4, 0.4));
	text.setFont(font);

	sf::RectangleShape rect(sf::Vector2f(10.0, 10.0));
	
	int cnt = 0;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				if (event.key.code == sf::Keyboard::H) {
					for (int i = 0; i < 100; i++) {
						for (Dots &item: dotsContainer) {
							item.move();
						}
						cnt++;
					}
				}
				if (event.key.code == sf::Keyboard::N) {
					for (Dots &item: dotsContainer) {
						item.move();
					}
					cnt++;
				}
				if (event.key.code == sf::Keyboard::B) {
					if (cnt > 0) {
						for (Dots &item: dotsContainer) {
							item.reverse_move();
						}
						cnt--;
					}
				}
			}
		}
		window.clear();
		text.setString("cnt: " + to_string(cnt));
		for (Dots &item: dotsContainer) {
			rect.setPosition(sf::Vector2f(50 + item.getY() * 10, 50 + item.getX() * 10));
			window.draw(rect);
		}
		window.draw(text);
		window.display();
	}
}

int main(int argc, char *argv[]) {
	vector<Dots> dotsContainer;
	ifstream file(argv[1]); // 파일 열기

	while (1) {
		char tmp;
		int x, y, v_x, v_y;
		file >> tmp >> tmp;
		file >> x >> tmp >> y;
		file >> tmp >> tmp;
		if (file.eof()) break;
		file >> v_x >> tmp >> v_y;
			dotsContainer.push_back(Dots(y, x, v_y, v_x));
	}
	print_sfml(dotsContainer);
	return 0;
}