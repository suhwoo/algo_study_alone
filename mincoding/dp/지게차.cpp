#include <iostream>
using namespace std;
int h, w;
int map[21][21];
int memo[21][21];
int from[21][21];
enum {
	DOWN = 1,
	RIGHT
};
int getMinPoint(int dy, int dx) {
	if (dy >= h || dx >= w)return 21e8;
	if (dy == h - 1 && dx == w - 1)return 0;
	if (memo[dy][dx] != 0)return memo[dy][dx];

	int a = getMinPoint(dy + 1, dx);
	int b = getMinPoint(dy, dx + 1);

	int mini = a;
	from[dy][dx] = DOWN;
	if (mini > b) {
		mini = b;
		from[dy][dx] = RIGHT;
	}
	memo[dy][dx] = mini + map[dy][dx];
	return memo[dy][dx];
	
}
int main() {
	cin >> h >> w;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			cin >> map[y][x];
		}
	}

	int ret = getMinPoint(0, 0);
	cout << ret << "\n";
	int y = 0;
	int x = 0;
	while (1) {
		cout << y << "," << x << "\n";
		if (y == h - 1 && x == w - 1)break;
		if (from[y][x] == DOWN)y++;
		else x++;
	}
	return 0;
}
