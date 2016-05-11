/**
Spiral Order Matrix I

Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
**/


#include <iostream>
#include <vector>

using namespace std;

vector<int> spiral(vector<vector<int> > &A) {
	vector<int> result;
	// t -> top initial position
	// b -> bottom initial position
	// l -> left initial position
	// r -> right initial position
	int t=0, b=A.size()-1, l=0, r=A[0].size()-1;
	// dir value
	// 0 -> left to right
	// 1 -> top to bottm
	// 2 -> right to left
	// 3 -> bottom to top
	int dir = 0;
	while(t <= b && l <= r) {
		if (dir == 0){
			for (int i=l; i<=r; i++)result.push_back(A[t][i]);
			t++;
		}
		else if (dir == 1){
			for (int i=t; i<=b; i++)result.push_back(A[i][r]);
			r--;
		}
		else if (dir == 2){
			for (int i=r; i>=l; i--)result.push_back(A[b][i]);
			b--;
		}
		else if (dir == 3){
			for (int i=b; i>=t; i--)result.push_back(A[i][l]);
			l++;
		}
		dir  = (dir+1)%4;
	}

	return result;
}

int main() {
	vector<vector<int> > A;

	int f[] = {1,2,3,4};
	int s[] = {5,6,7,8};
	int t[] = {9,10,11,12};

	vector<int> first(f, f + sizeof f / sizeof f[0]);
	vector<int> second(s, s + sizeof s / sizeof s[0]);
	vector<int> third(t, t + sizeof t / sizeof t[0]);

	A.push_back(first);
	A.push_back(second);
	A.push_back(third);

	vector<int> B = spiral(A);
	for (int i=0; i<B.size(); i++) {
		cout << B[i] << endl;
	}
	return 0;
}
