#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void swap(int &x, int &y) {
    int temp = x;
	x = y;
	y = temp;
}

void wave(vector<int> &A) {
    sort(A.begin(), A.end());
	for(int s=0; s<A.size()-1; s+=2) {
        swap(A[s], A[s+1]);
	}
}


int main() {
	int arr[] = {1, 2, 3, 4, 5, 2, 2, 0};
	vector<int> X (arr, arr + sizeof(arr) / sizeof(arr[0]));
	wave(X);
	for (int i=0; i<X.size(); i++) {
		cout << X[i] << endl;
	}
	return 0;
}