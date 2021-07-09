#include <iostream>
#include <algorithm>
using namespace std;
unsigned int bagNum[5001];
int main() {
	unsigned int totalWeight;
	cin >> totalWeight;
	bagNum[3] = 1;
	bagNum[5] = 1;
	for (int index = 6; index <= totalWeight; index++) {
		if (index % 5 == 0) {
			bagNum[index] = bagNum[index-5] + 1;
		}
		else if (index % 3 == 0) {
			bagNum[index] = bagNum[index - 3] + 1;
		}
		else {
			if (bagNum[index - 5] != 0 && bagNum[index - 3] == 0) {
				bagNum[index] = bagNum[index - 5] + 1;
			}
			else if (bagNum[index - 5] == 0 && bagNum[index - 3] != 0) {
				bagNum[index] = bagNum[index - 3] + 1;
			}
			else if (bagNum[index - 5] != 0 && bagNum[index - 3] != 0) {
				bagNum[index] = min(bagNum[index - 5], bagNum[index - 3]) + 1;
			}
			else {
				bagNum[index] = 0;
			}
		}
	}
	if (bagNum[totalWeight] != 0) {
		cout << bagNum[totalWeight];
	}
	else {
		cout << "-1";
	}
	return 0;
}