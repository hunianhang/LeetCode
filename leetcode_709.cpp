#include <string>
#include <iostream>
#include <cctype>

using namespace std;

class Solution
{
public:
	string toLowerCase(string s)
	{
		for (char &c : s) {  //Traverse the string using for (char& c : s) and modify each character in original place.
			c = tolower(c);
		}

		return s;
	}
};

int main(void)
{
	Solution sol;
	string s = "Hello, WorLD!";
	string result = sol.toLowerCase(s);
	cout << "LowerCase string: " << result << endl;
	return 0;
}