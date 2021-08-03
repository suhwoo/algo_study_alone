#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int y, x;
};
queue<Node> q;
int map[5][8];
int direct[4][2] = { 1,0,-1,0,0,1,0,-1 };
void bfs(int y, int x) {
	Node now = { y,x };
	q.push(now);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny < 0 || nx < 0 || ny>4 || nx>7) continue;
			if (map[ny][nx] == 0)continue;
			map[ny][nx] = 0;
			q.push({ ny,nx });
		}
	}
}
int main() {
	int cnt = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 8; x++) {
			cin >> map[y][x];
		}
	}
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 8; x++) {
			if (map[y][x] == 1) {
				bfs(y, x);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
