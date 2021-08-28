#include <iostream>
#include <queue>
using namespace std;
int direct[4][2] = { 0,1,1,0,-1,0,0,-1 };
int map[1001][1001];
int m, n;
int cnt;
struct Node {
	int y, x;

};
queue<Node> q;
void bfs() {
	
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny<0 || nx<0 || ny>n - 1 || nx>m - 1) continue;
			if (map[ny][nx] != 0)continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			cnt = map[ny][nx];
			q.push({ ny, nx });
		}
	}
}
int main() {
	
	cin >> m >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) {
				Node temp = { y,x };
				q.push(temp);
			}
		}
	}
	bfs();
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (map[y][x] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}
	if (cnt == 0)cout << 0;
	else { cout << cnt - 1; }
	return 0;
}
