class Solution:
    def fourSum(self, nums:list[int], target:int) -> list[list[int]]:
        nums.sort()

        n = len(nums)
        res_set = set()

        for i in range(n - 3):
            for j in range(i + 1, n - 2):
                left = j + 1
                right = n - 1
                while left < right:
                    s = nums[i] + nums[j] + nums[left] + nums[right]
                    if s == target:
                        res_set.add((nums[i], nums[j], nums[left], nums[right]))
                        left += 1
                        right -= 1
                        break
                    elif s < target:
                        left += 1
                    else:
                        right -= 1

        return [list(s) for s in res_set]


if __name__ == '__main__':
    s = Solution()
    print(s.fourSum([1, 0, -1, 0, -2, 2], 0))
    print(s.fourSum([2, 2, 2, 2, 2], 8))