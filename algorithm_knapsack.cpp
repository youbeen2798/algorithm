#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int w[101], v[101];
int dp[101][100001];

int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else
		return b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i]; //각 물건의 무게와 가치
	}

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (w[i] <= j) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k];


}