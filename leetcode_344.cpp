#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int left = 0;
		int right = s.size() - 1;

		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
};

int main(void)
{
	Solution sol;
	vector<char> s = { 'h','e','l','o' };

	sol.reverseString(s);

	cout << "Reversed string:";
	for (char c : s) {
		cout << c << " ";
	}
	cout << endl;

	return 0;
}