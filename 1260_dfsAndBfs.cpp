#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct setByNodeName {};
struct Node {
	unsigned int nodeName;
	bool isVisit = false;
	set<Node*, setByNodeName> linkedNode;
};
struct setByNodeName {
	bool operator() (const Node* left, const Node* right) const {
		if (left->nodeName < right->nodeName) {
			return left->nodeName < right->nodeName;
		}
	}
};
vector<Node*> allNode;
int dfs(Node* nowNode) {
	nowNode->isVisit = true;

}
int main() {
	unsigned int nodeNum;
	unsigned int lineNum;
	unsigned int startPoint;
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
		allNode[firstPoint]->linkedNode.insert(allNode[otherPoint]);
		allNode[otherPoint]->linkedNode.insert(allNode[firstPoint]);
	}
	dfs(allNode[startPoint]);

	return 0;
}