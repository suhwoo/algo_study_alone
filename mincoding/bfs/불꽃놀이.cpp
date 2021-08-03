#include <iostream>
#include <queue>
using namespace std;
int map[4][5];
struct Node {
	int y;
	int x;
};
queue<Node> q;
int direct[8][2] = {
0,-1,
-1,-1,
-1,0,
-1,1,
0,1,
1,1,
1,0,
1,-1 };
int main() {
	Node now;
	int maxi = -1;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) {
				q.push({y,x});

			}
		}
	}
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int t = 0; t < 8; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny < 0 || nx < 0 || ny>3 || nx>4)continue;
			if (map[ny][nx] != 0)continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			if (maxi < map[ny][nx]) {
				maxi = map[ny][nx];
			}
			q.push({ ny,nx });

		}
	}
	cout << maxi-1;
}
