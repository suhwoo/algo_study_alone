#include <iostream>
#include <queue>
using namespace std;
int map[4][4];
struct Node {
	int y, x;
	int lev;
};
queue<Node> q;
int direct[4][2] = { 1,0,0,1,-1,0,0,-1 };
int main() {
	int cnt = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}
	Node now = { 0,0,1 };
	q.push(now);
	map[0][0] = 0;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		cnt++;
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny < 0 || nx < 0 || ny>3 || nx>3)continue;
			if (map[ny][nx] == 0)continue;
			map[ny][nx] = 0;
			q.push({ ny,nx,now.lev + 1 });

		}
	}
	cout << cnt;
	int i;
	cin >> i;
}
