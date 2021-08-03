#include<iostream>
#include<queue>
using namespace std;
int map[1000][1000];
struct Node {
	int y;
	int x;
};
queue<Node> q;
int direct[4][2] = { 0,1,0,-1,1,0,-1,0 };
int main() {
	int input;
	int inputMapy;
	int inputMapx;
	int maxi = -1;
	cin >> inputMapy >> inputMapx;
	for (int y = 0; y < inputMapy; y++) {
		for (int x = 0; x < inputMapx; x++) {
			cin >> input;
			if (input == 0) {
				map[y][x] = 0;
			}
			else if (input == 1) {
				map[y][x] = -1;
			}
		}
	}
	int y, x;
	cin >> y >> x;
	Node now = { y,x };
	map[y][x] = 1;
	q.push(now);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny<0 || nx<0 || ny>inputMapy - 1 || nx>inputMapx - 1)continue;
			if (map[ny][nx] != 0)continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			if (maxi < map[ny][nx]) {
				maxi = map[ny][nx];
			}
			q.push({ ny,nx });
		}
	}
	cout << maxi-1;
	return 0;
}
