#include <iostream>
#include <vector>
#include <algorithm>
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
	nowNode->isVisit = true;
	if (nowNode->parentNode == -2) {
		return;
	}
	if (nowNode->childNode.size() == 0) {
		leafNodeNum++;
		return;
	}
	for (int i = 0; i < nowNode->childNode.size(); i++) {
		if (allNode[nowNode->childNode[i]]->isVisit == false) {
			dfs(allNode[nowNode->childNode[i]]);
		}
	}
}
int main() {
	//트리생성
	int NodeNum;
	int parentNodeNum;
	int eraseNodeNum;
	int whereIsEraseIndex;
	cin >> NodeNum;
	for (int i = 0; i < NodeNum; i++) {
		Node* tempNode = new Node;
		tempNode->nodeName = i;
		allNode.push_back(tempNode);
	}
	for (int i = 0; i < NodeNum; i++) {
		cin >> parentNodeNum;
		allNode[i]->parentNode = parentNodeNum;
		if (parentNodeNum != -1) {
			allNode[parentNodeNum]->childNode.push_back(i);
		}
	}
    /*
        outOfBound
        tempNode만들고 바로 부모노드번호 넣으면 
        if(parentNodeNum != -1){
            allNode[parentNode]에서 vector에 들어있지않은 인덱스일 수 있다.
        }
        예제는 4 3 3 3 -1 0
    */
	//노드 하나 연결 끊기
	cin >> eraseNodeNum;
	//본인-parent쪽 연결도 끊고
	allNode[eraseNodeNum]->parentNode = -2;
    /*
        이부분 안 끊으면 5 -1 0 0 1 1 0 예제에서 3이 나온다.
        어차피 얘가 루트니까.. 위의 부모에서 잘라봤자 소용이 없음
    */
	//parent-본인 연결도 끊고.
	for (int i = 0; i < NodeNum; i++) {
		auto it = find(allNode[i]->childNode.begin(), allNode[i]->childNode.end(), eraseNodeNum);
		if (it != allNode[i]->childNode.end()) {
			allNode[i]->childNode.erase(it);
		}
	}
    /*
        이부분 안 끊으면 2 -1 0 1 예제에서 0이 나온다. 
        자식을 안 끊으면 leaf로 판단이 안되서 0이 나온다. 
        제대로 된 값은 루트도 단말이 될 수 있으므로 1이 정답.
    */
	//루트가 -1인 트리들의 리프 구하기(dfs)
	for (int i = 0; i < NodeNum; i++) {
		if (allNode[i]->parentNode == -1) {
			dfs(allNode[i]);
		}
	}
	cout << leafNodeNum;
	return 0;
}
