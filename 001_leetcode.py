class Solution:
    def twoSum(self,nums,target):
        seem = {}
        for i,num in enumerate(nums):
            complement = target - num
            if complement in seem:
                return [seem[complement],i]
            seem[num] = i

        return []


def main():
    print("---- Two Sum Problem ----")

    nums_str = input("Enter numbers separated by a spaces(e.g. 2 7 11 15): ")
    nums = list(map(int,nums_str.split()))
    target = int(input("Enter target: "))

    result = Solution().twoSum(nums,target)

    if result != []:
        print(f"Indices:{result}")
        print(f"Values: {nums[result[0]]} + {nums[result[1]]} = {target}")
    else:
        print("No two numbers add up to target.")


if __name__ == '__main__':
    main()