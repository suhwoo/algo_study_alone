#include <iostream>
#include <queue>
using namespace std;
int cnt;
int nowY, nowX;

int map[3][5] = {
	0,0,0,0,-1,
	-1,0,-1,0,0,
	0,0,0,0,-1
};
struct Node {
	int y, x;
	int level = 0;
};
queue<Node> q;
int direct[4][2] = { 0,1,1,0,-1,0,0,-1 };

void bfs(int endY,int endX) {
	while (!q.empty()) {
		q.pop();
	}
	Node now;
	now.y = nowY;
	now.x = nowX;
	map[nowY][nowX] = 1;
	q.push(now);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny < 0 || nx < 0 || ny > 2 || nx > 4) { continue; }
			if (map[ny][nx] == -1||map[ny][nx]==1)continue;
			map[ny][nx] = 1;
			Node temp;
			temp.y = ny;
			temp.x = nx;
			temp.level = now.level + 1;
			if (ny == endY && nx == endX) {
				nowY = ny;
				nowX = nx;
				cnt += now.level + 1;
				return;
			}
			q.push(temp);

		}
	}

}
int main() {
	int cheeseY, cheeseX;
	int friendY, friendX;
	cin >> cheeseY >> cheeseX;
	cin >> friendY >> friendX;
	bfs(cheeseY, cheeseX);
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 5; x++) {
			if (map[y][x] != -1)map[y][x] = 0;
		}
	}
	bfs(friendY,friendX);
	cout << cnt;
}
