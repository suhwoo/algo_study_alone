#include <iostream>
#include <stack>
using namespace std;
struct Node {
	int y; 
	int x;
};
int map[21][21];
Node direct[21][21];
stack<Node> s;
void init(int mapH,int mapW) {
	for (int x = 1; x < mapW; x++) {
		map[0][x] = map[0][x] + map[0][x - 1];
		direct[0][x] = { 0,x - 1 };
	}
	for (int y = 1; y < mapH; y++) {
		map[y][0] = map[y][0] + map[y - 1][0];
		direct[y][0] = { y - 1,0 };
	}
}
int main() {
	int mapH;
	int mapW;
	cin >> mapH >> mapW;
	for (int y = 0; y < mapH; y++) {
		for (int x = 0; x < mapW; x++) {
			cin >> map[y][x];
		}
	}
	init(mapH,mapW);
	for (int y = 1; y < mapH; y++) {
		for (int x = 1; x < mapW; x++) {
			if (map[y][x] + map[y - 1][x]<= map[y][x] + map[y][x - 1]) {
				//위에서 온 경우, 만약 같을 경우 위에서 오는 거가 먼저다.
				map[y][x] = map[y][x] + map[y - 1][x];
				direct[y][x] = { y - 1,x };
			}
			else {
				//왼쪽에서 온 경우
				map[y][x] = map[y][x] + map[y][x - 1];
				direct[y][x] = { y,x - 1 };
			}
		}
	}
	cout << map[mapH - 1][mapW - 1] << "\n";
	int goHP = mapH - 1;
	int tempHP;
	int goWP = mapW - 1;
	while (1) {
		if (goHP == 0 && goWP == 0)break;
		s.push(direct[goHP][goWP]);
		tempHP = direct[goHP][goWP].y;
		goWP = direct[goHP][goWP].x;
		goHP = tempHP;
	}
	while (!s.empty()) {
		Node now = s.top();
		cout << now.y << "," << now.x << "\n";
		s.pop();
	}
	cout << mapH - 1 << "," << mapW - 1 << "\n";
	cin >> goHP;
	return 0;
}
