#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum_brute_force(vector<int>& nums, int target)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					return { i,j };
				}
			}
		}

		return {};
	}

	vector<int> twoSum_optimization(vector<int>& nums, int target)
	{
		unordered_map<int, int> hashMap;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int i = 0; i < nums.size(); i++)
			{
				int complement = target - nums[i];
				if (hashMap.find(complement) != hashMap.end())
				{
					return { hashMap[complement],i };
				}
				hashMap[nums[i]] = i;
			}
			return {};
		}
	}
};

int main()
{
	Solution sol;
	vector<int> nums = { 2,3,11,15,7};
	int target = 9;
	vector<int> result = sol.twoSum_optimization(nums, target);

	if (!result.empty())
	{
		cout << "Indices found: " << result[0] << "," << result[1] << endl;
	}
	else
	{
		cout << "No two sum solution found." << endl;
	}

	return 0;
}