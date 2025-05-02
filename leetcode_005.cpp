#include<iostream>
#include <string>

using namespace std;


string expandAroundCenter(const string& s, int left, int right) {
	while (left >= 0 && right < s.size() && s[left] == s[right]) {
		left--;
		right++;
	}

	return s.substr(left + 1, right - left - 1);
}

string longestPalindrom(string s)
{
	if (s.empty())
		return "";

	string result;

	for (int i = 0; i < s.size(); i++) {
		string oddLenPalindrome = expandAroundCenter(s, i, i);
		string evenLenPalindrome = expandAroundCenter(s, i, i + 1);

		if (oddLenPalindrome.length() > result.length()) {
			result = oddLenPalindrome;
		}
		if (evenLenPalindrome.length() > result.length()) {
			result = evenLenPalindrome;
		}
	}

	return result;
}

int main(void)
{
	string input;
	cout << "Enter the string: ";
	cin >> input;
	string result = longestPalindrom(input);

	cout << "Longest Palindromic Substring: " << result << endl;
	return 0;
}
