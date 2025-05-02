#include<iostream>
#include<string>
#include<cctype>

using namespace std;

class Solution {
public:
	int lengthOflastWord(string s) {
		int i = s.length() - 1;
		int length = 0;

		while (i >= 0 && isspace(s[i])) {
			i--;
		}

		while (i >= 0 && !isspace(s[i]))
		{
			length++;
			i--;
		}

		return length;
	}
};

int main(void)
{
	Solution sol;
	string s = "fly me ato terler ";
	cout << "Length of last word: " << sol.lengthOflastWord(s) << endl;
	return 0;
}