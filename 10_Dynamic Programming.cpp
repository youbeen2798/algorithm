#include <iostream>

using namespace std;

int dp[100];

int fibonacci(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	if (dp[n] !=  0)
		return dp[n];
	return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fibonacci(5);
}
