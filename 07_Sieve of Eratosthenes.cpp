//숫자 2개(n, m)을 입력했을 때, n 이상 m 이하의 소수들을 출력해주는 코드

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <bool> check(int n) { //소수 구하는 함수 (에라토스테네스의 체)
	vector <bool> v(n+1);
	v[0] = 1;
	v[1] = 1;

	for (int i = 2; i <= sqrt(n); i++) { //n까지 소수를 알고 싶을 때, 제곱근 이하의 수의 배수만 지우면 된다!
		if (v[i] == 1) {
			continue;
		}
		for (int j = 2 * i; j <= n; j += i) {
			v[j] = 1;
		}
	}

	return v;

}
int main() {
	ios_base::sync_with_stdio(0); //입출력 빠르게
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;

	vector <bool> v = check(n); // 함수 반환하여 벡터 v에 저장

	vector <int> vt;

	int sum = 0;
	for (int i = m; i <= n; i++) { //소수인것만 따로 벡터 vt에 저장
		if (v[i] == 0) {
			sum += i;
			vt.push_back(i);
		}
	}
	
	for (int i = 0; i < vt.size(); i++) {
		cout << vt[i] << " ";
	}


}