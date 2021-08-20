#include <iostream>
#include <queue>
using namespace std;
int startX, startY;
int endX, endY;
int cnt;
struct Node {
	int y;
	int x;
};
queue<Node> q;
int direct[4][2] = { 0,1,1,0,-1,0,0,-1 };
int map[4][4] = {
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	1,0,1,0
};
void bfs(Node now) {
	q.push(now);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny < 0 || nx < 0 || ny>3 || nx>3)continue;
			if (map[ny][nx] != 0)continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			if (ny == endY && nx == endX)return;
			q.push({ny, nx});

		}
	}
}
int main() {

	cin >> startY >> startX;
	cin >> endY >> endX;
	Node now = { startY,startX };
	bfs(now);
	cout << map[endY][endX] << "회";
	return 0;
}
