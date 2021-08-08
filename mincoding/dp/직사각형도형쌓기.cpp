#include <iostream>
using namespace std;
int memo[100];
int findCases(int dan) {
	if (dan == 0)return 1;
	if (dan == 1)return 1;
	if (dan < 0)return 21e8;
	if (memo[dan] != 0)return memo[dan];

	int beforetwo = findCases(dan - 2);
	int beforeone = findCases(dan - 1);

	int now = beforeone + beforetwo;
	memo[dan] = now;

	return now;
}
int main() {
	int dan;
	cin >> dan;
	memo[0] = 1;
	memo[1] = 1;
	int ret=findCases(dan);
	cout << ret;
	return 0;
}
