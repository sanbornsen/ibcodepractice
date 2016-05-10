#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateArray(vector<int> &A, int B) {
	vector<int> ret;
	int r = B % A.size();
	for (int i = 0; i < A.size(); i++) {
		if ((i+r) >= A.size()) {
			ret.push_back(A[i+r - A.size()]);
		} else {
			ret.push_back(A[i + r]);
		}
	}
	return ret;
}

int main() {
	int arr[19] = {14, 5, 14, 34, 42, 63, 17, 25, 39, 61, 97, 55, 33, 96, 62, 32, 98, 77, 35};
	vector<int> A (arr, arr + sizeof arr / sizeof arr[0]);
	int B = 56;

	vector<int> res = rotateArray(A, B);

	for (int i = 0; i<res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}

