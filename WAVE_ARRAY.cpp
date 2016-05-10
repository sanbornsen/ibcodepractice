/**

Wave Array

Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]

NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.
So, in example case, you will return [2, 1, 4, 3]
**/



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