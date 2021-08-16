#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string novel = "BOBOOBOBOBOBBM";
unordered_map<string,int> wordList;

void init() {
	for (int wordPoint = 0; wordPoint <= novel.size() - 3; wordPoint++) {
		string word = novel.substr(wordPoint, 3);
		wordList[word]++;
	}
}
int main() {
	init();
	int num;
	string word;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> word;
		cout << wordList[word] << "\n";
	}
	return 0;
}
