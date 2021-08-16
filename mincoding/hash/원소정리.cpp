#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;

string inputLine;
unordered_map<char, int> cnt;

void init() {
	for (auto a = 'A'; a <= 'F'; a++) {
		cnt[a] = 0;
	}
	for (int i = 0; i < inputLine.size(); i++) {
		if (inputLine[i] < 97) {
			cnt[inputLine[i]]++;
		}
		else {
			cnt[inputLine[i] - 32]++;
		}
	}
}
int main() {
	cin >> inputLine;
	init();
	for (auto i = 'A'; i <='F'; ++i) {
		cout <<i<<':'<< cnt[i] << "\n";
	}
	return 0;
}
