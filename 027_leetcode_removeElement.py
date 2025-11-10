class Solution:
    def removeElement(self, nums, val):
        i = 0

        for j in range(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1

        return i

if __name__ == '__main__':
    s = Solution()
    nums = [1,2,3,4,5,6,7]
    val = 3
    print(s.removeElement(nums, val))
