#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int lengthOfLongestSubstring(const string s)
{
	unordered_set<char> seen;
	int left = 0;
	int maxLength = 0;

	for (int right = 0; right<s.size(); right++)
	{
		while (seen.count(s[right])) {
			seen.erase(s[left++]);
		}
		seen.insert(s[right]);
		maxLength = max(maxLength, right - left + 1);
	}

	return maxLength;

}

pair<int, string>longestSubstringWithoutRepeatingImprove(string s)
{
	unordered_set<char> seen;
	int left = 0; 
	int maxLen = 0;
	int start = 0;

	for (int right = 0; right < s.size(); right++)
	{
		while (seen.count(s[right])) {
			seen.erase(s[left++]);
		}
		seen.insert(s[right]);
		if (right - left + 1 > maxLen) {
			maxLen = right - left + 1;
			start = left;
		}
	}

	return { maxLen, s.substr(start,maxLen) };
}

int main_method1(void)
{
	string input;
	cout << "Enter a string:";
	cin >> input;
	
	int result = lengthOfLongestSubstring(input);
	cout << "Length of longest substring without repeating characters: " << result << endl;
	return 0;
}

int main_459(void)
{

	string input;
	cout << "Enter a string:";
	cin >> input;
	pair <int, string> result  = longestSubstringWithoutRepeatingImprove(input);
	cout << "Length: " << result.first << endl;
	cout << "Substring: " << result.second << endl;
	return 0;
}

