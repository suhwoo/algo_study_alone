#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
	int y;
	int x;
};
int map[101][101];
queue<Node> q;
int direct[4][2] = {0,1,0,-1,1,0,-1,0};
int main() {
	int mapSize;
	Node first;
	Node second;
	Node now;
	cin >> mapSize;
	cin >> first.y;
	cin >> first.x;
	cin >> second.y;
	cin >> second.x;
	q.push(first);
	q.push(second);
	map[first.y][first.x] = 1;
	map[second.y][second.x] = 1;

	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny<0 || nx<0 || ny>mapSize - 1 || nx>mapSize - 1)continue;
			if (map[ny][nx] != 0)continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
	for (int y = 0; y < mapSize; y++) {
		for (int x = 0; x < mapSize; x++) {
			cout << map[y][x];
		}
		cout << "\n";
	}
	return 0;
}
