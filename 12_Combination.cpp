#include <iostream>
#include <vector>
using namespace std;

void combination(vector <int> v, vector <int> comb, int r, int index, int depth) {

	if (r == 0) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
	}
	else if (depth == v.size()) {
		return;
	}
	else {
		comb[index] = v[depth];

		combination(v, comb, r - 1, index + 1, depth+1);
		combination(v, comb, r, index, depth + 1);
	}
}
int main() {

	vector <int> v = { 1,2,3,4,5 };

	for (int r = 1; r <= v.size(); r++) {
		vector <int> comb(r);
		combination(v, comb, r, 0, 0);
	}


}