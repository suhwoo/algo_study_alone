#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> yearList;

void init() {
	int dinoList[8] = { 5,6,35,2,11,5,15,25 };
	for (int i = 0; i < 8; i++) {
		yearList[dinoList[i]]++;
	}
}
int main() {
	init();
	int year;
	cin >> year;
	int findyear = year - 1000000000;
	cout << yearList[findyear] << "마리\n";
	return 0;
}
