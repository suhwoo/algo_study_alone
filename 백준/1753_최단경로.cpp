#include <iostream>
#include <vector>
using namespace std;
struct edge {
	int weight;
	int startP;
	int endP;
};
struct Node {
	int totalW=100000;
	vector<edge> goList;
};
vector<Node> nodeList;
void findRoute(int now) {
	Node nowNode = nodeList[now];
	for (int members = 0; members < nowNode.goList.size(); members++) {
		if (nodeList[nowNode.goList[members].endP].totalW > nowNode.totalW + nowNode.goList[members].weight) {
			nodeList[nowNode.goList[members].endP].totalW = nowNode.totalW + nowNode.goList[members].weight;
		}
		findRoute(nowNode.goList[members].endP);
	}
}
int main() {
	int ve, e;
	int u, v, w;
	int startV;
	cin >> ve >> e;
	cin >> startV;
	for (int i = 0; i <= ve; i++) {
		Node temp;
		nodeList.push_back(temp);
	}
	for (int i = 0; i < e; i++) {
		cin >> u >> v >> w;
		edge temp = { w,u,v };
		nodeList[u].goList.push_back(temp);
	}
	nodeList[startV].totalW = 0;
	findRoute(startV);
	for (int t = 1; t <= ve; t++) {
		if (nodeList[t].totalW == 100000) {
			cout << "INF" << "\n";
		}
		else {
			cout << nodeList[t].totalW << "\n";
		}
	}
	return 0;
}
