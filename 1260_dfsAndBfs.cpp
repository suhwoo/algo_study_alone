#include <iostream>
#include <vector>
#include <set>
using namespace std;
unsigned int startPoint;

struct Node {
	unsigned int nodeName;
	bool isVisit = false;
	set<unsigned int> linkedNode;
};
vector<Node*> allNode;
void dfs(Node* nowNode) {
	nowNode->isVisit = true;
	if (nowNode->nodeName == startPoint) {
		cout << nowNode->nodeName;
	}
	else {
		cout << " " << nowNode->nodeName;
	}
	for (auto it = nowNode->linkedNode.begin(); it != nowNode->linkedNode.end(); it++) {
		if (allNode[*it]->isVisit == false) {
			dfs(allNode[*it]);
		}
	}
}
int main() {
	unsigned int nodeNum;
	unsigned int lineNum;
	unsigned int firstPoint = 0;
	unsigned int otherPoint = 0;
	cin >> nodeNum >> lineNum >> startPoint;
	//to fill index 0
	Node* tempNode = new Node;
	allNode.push_back(tempNode);
	for (int i = 1; i <= nodeNum; i++) {
		Node* tempNode = new Node;
		tempNode->nodeName = i;
		allNode.push_back(tempNode);
	}
	for (int i = 0; i < lineNum; i++) {
		cin >> firstPoint >> otherPoint;
		allNode[firstPoint]->linkedNode.insert(otherPoint);
		allNode[otherPoint]->linkedNode.insert(firstPoint);
	}
	dfs(allNode[startPoint]);
	return 0;
}