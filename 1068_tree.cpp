#include <iostream>
#include <vector>
using namespace std;
int leafNodeNum;
struct Node {
	int nodeName;
	int parentNode;
	bool isVisit = false;
	vector<int> childNode;
};
vector<Node*> allNode;
void dfs(Node* nowNode) {
	
}
int main() {
	//트리생성
	int NodeNum;
	int parentNodeNum;
	int eraseNodeNum;
	cin >> NodeNum;
	for (int i = 0; i < NodeNum; i++) {
		Node* tempNode = new Node;
		tempNode->nodeName = i;
		cin >> parentNodeNum;
		tempNode->parentNode = parentNodeNum;
		allNode.push_back(tempNode);
		if (parentNodeNum != -1) {
			allNode[parentNodeNum]->childNode.push_back(i);
		}
	}
	//노드 하나 연결 끊기
	cin >> eraseNodeNum;
	allNode[eraseNodeNum]->parentNode = -2;
	//루트가 -1인 트리들의 리프 구하기(dfs)
	for (int i = 0; i < NodeNum; i++) {
		if (allNode[i]->parentNode == -1) {
			dfs(allNode[i]);
		}
	}
	return 0;
}