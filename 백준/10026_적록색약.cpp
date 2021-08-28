#include <iostream>
#include <queue>
using namespace std;
char mapN[101][101];
char mapY[101][101];
int cntN;
int cntY;
int n;
struct Node {
	int y, x;
};
int direct[4][2] = { 0,1,1,0,-1,0,0,-1 };
void bfsFornoP(int y,int x,char col) {
	queue<Node> q;
	Node now = { y,x };
	q.push(now);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny<0 || nx<0 || ny>n - 1 || nx>n - 1) continue;
			if (mapN[ny][nx] == 0)continue;
			if (mapN[ny][nx] != col)continue;
			mapN[ny][nx] = 0;
			q.push({ ny,nx });
		}
	}
}
void bfsForyesP(int y,int x,char col) {
	queue<Node> q;
	Node now = { y,x };
	q.push(now);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny<0 || nx<0 || ny>n - 1 || nx>n - 1) continue;
			if (mapY[ny][nx] == 0)continue;
			if (mapY[ny][nx] != col)continue;
			mapY[ny][nx] = 0;
			q.push({ ny,nx });
		}
	}
	
}
int main() {
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> mapN[y][x];
			mapY[y][x] = mapN[y][x];
			if (mapY[y][x] == 'G') {
				mapY[y][x]='R';
			}
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (mapN[y][x] != 0) {
				bfsFornoP(y,x,mapN[y][x]);
				cntN++;
			}
			if (mapY[y][x] != 0) {
				bfsForyesP(y,x,mapY[y][x]);
				cntY++;
			}
		}
	}
	cout << cntN << " " << cntY;
	return 0;
}
