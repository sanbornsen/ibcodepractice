/**
Largest Number

Link - https://www.interviewbit.com/problems/largest-number/

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(int i, int j) {
	return to_string(j)+to_string(i) < to_string(i)+to_string(j);
}

int main() {
	int a[] = {0, 0, 0, 0};
	vector<int> A(a, a + sizeof(a) / sizeof(a[0]));

	sort(A.begin(), A.end(), compare);
	string str;
	for (int i = 0; i < A.size(); i++) {
	 	str += to_string(A[i]);
	}

	while(str[0] == '0'){
		str.erase(str.begin());
	}
	if (!str.length()) {
		str = '0';
	}

	cout << str << endl;
	return 0;
}