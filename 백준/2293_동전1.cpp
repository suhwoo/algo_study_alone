#include <iostream>
#define max 101
using namespace std;
int coinKind[max];
int dp[10001];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coinKind[i];
	}
	dp[0] = 1;
	for (int coinNum = 0; coinNum < n; coinNum++) {
		for (int indexNum = coinKind[coinNum]; indexNum <= k; indexNum++) {
			dp[indexNum] = dp[indexNum] + dp[indexNum - coinKind[coinNum]];
		}
	}
	cout << dp[k] << "\n";
	return 0;
}
