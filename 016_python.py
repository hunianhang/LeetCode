class Solution:
    def threeSumClosest(self, nums:list[int], target: int) -> int:
        nums.sort()
        n = len(nums)

        closest = float('inf')

        for i in range(n - 2):
            left, right = i+1, n-1

            while left < right:
                s = nums[i] + nums[left] + nums[right]

                if abs(s - target) < abs(closest - target):
                    closest = s

                if s < target:
                    left += 1
                elif s > target:
                    right -= 1
                else:
                    return s

        return closest


if __name__ == '__main__':
    s = Solution()
    print(s.threeSumClosest([-1, 0, 1, 2, -1, -4], 2))
    print(s.threeSumClosest([0, 0, 0], 1))  # 输出: 0
    print(s.threeSumClosest([1, 1, 1, 1], 0))  # 输出: 3