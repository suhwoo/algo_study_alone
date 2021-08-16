#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

unordered_map<string, int> nameList;
queue<string> q;

void init() {
	nameList.insert({ "POP",1 });
	nameList.insert({ "TOM",1 });
	nameList.insert({ "MC",1 });
	nameList.insert({ "JASON",1 });
	nameList.insert({ "KFC",1 });
}
int main() {
	init();
	int num;
	string name;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> name;
		if (nameList[name] == 1) {
			q.push("yes");
		}
		else {
			q.push("no");
		}
	}
	while (!q.empty()) {
		cout << q.front()<<"\n";
		q.pop();
	}

	return 0;
}
