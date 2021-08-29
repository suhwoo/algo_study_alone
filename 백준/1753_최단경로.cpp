#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000
using namespace std;
struct edge {
	int dest;
	int cost;
};
struct vertex {
	vector<edge> togo;
	int totalCost = INF;
};
vector<vertex> vertexList;
void inputVer(int v,int e,int startV) {
	int a, b, c;
	for (int t = 0; t <= v; t++) {
		vertex temp;
		vertexList.push_back(temp);
	}
	for (int t = 0; t < e; t++) {
		cin >> a >> b >> c;
		edge temp = { b,c };
		vertexList[a].togo.push_back(temp);
	}
}
void solution(int startV,int v) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, startV));
	vertexList[startV].totalCost = 0;
	while (!pq.empty()) {
		int nowV = pq.top().second;
		int nowCost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < vertexList[nowV].togo.size(); i++) {
			int nextV = vertexList[nowV].togo[i].dest;
			int nextCost = vertexList[nowV].togo[i].cost;

			if (vertexList[nextV].totalCost > nowCost + nextCost) {
				vertexList[nextV].totalCost = nowCost + nextCost;
				pq.push(make_pair(-vertexList[nextV].totalCost, nextV));
			}

		}
	}
	for (int i = 1; i <= v; i++) {
		if (vertexList[i].totalCost == INF)cout << "INF" << "\n";
		else cout << vertexList[i].totalCost << "\n";
	}
}
int main() {
	int v, e, startV;
	cin >> v >> e >> startV;
	inputVer(v,e,startV);
	solution(startV,v);
	return 0;
}
