#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_multimap<char, int> members;
vector<int> arrayMember;

void init() {
	members.insert({ 'A',21 });
	members.insert({ 'E',15 });
	members.insert({ 'E',6 });
	members.insert({ 'A',15 });
	members.insert({ 'E',34 });
	members.insert({ 'B',32 });
	members.insert({ 'C',35 });
	members.insert({ 'C',36 });
	members.insert({ 'D',14 });
	members.insert({ 'A',3 });

}
int main() {
	init();
	char inputChar;
	cin >> inputChar;
	auto rangeOfMember = members.equal_range(inputChar);
	for (auto member = rangeOfMember.first; member != rangeOfMember.second; ++member) {
		arrayMember.push_back(member->second);
	}

	for (int i = 0; i < arrayMember.size(); i++) {
		cout << arrayMember[i];
		if (i != arrayMember.size() - 1)cout << " ";
	}

	return 0;
}
