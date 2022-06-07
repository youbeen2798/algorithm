///N개의 정수가 주어질 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램
//존재한다면 1을 존재하지 않으면 0을 출력

#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];

int n, m;

int binarysearch(int target) {
	int st = 0;
	int en = n - 1;
	while (st <= en) {
		int mid = (st + en) / 2;

		if (arr[mid] > target) {
			en = mid - 1;
		}
		else if (arr[mid] < target) {
			st = mid + 1;
		}
		else {
			return 1;
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	cin >> m;

	while (m--) {
		int k;
		cin >> k;

		cout << binarysearch(k) << "\n";
	}

}
