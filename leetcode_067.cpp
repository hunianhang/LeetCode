#include <iostream>
#include<string>
#include <algorithm>	
using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		string result = "";
		int a_len = a.size() - 1;
		int b_len = b.size() - 1;
		int carry = 0;

		while (a_len >= 0 || b_len >= 0 || carry != 0) 
		{
			int sum = carry;
			if (a_len >= 0) 
			{
				sum += a[a_len--] - '0';
			}
			if (b_len >= 0)
			{
				sum += b[b_len--] - '0';
			}
			result += (sum % 2) + '0';
			carry = sum / 2;
		}
		reverse(result.begin(), result.end());
		return result;
	}

};

int main()
{
	Solution sol;
	string a = "1010";
	string b = "1011";

	string result = sol.addBinary(a, b);
	cout << "result: " << result << endl;

	return 0;
}
