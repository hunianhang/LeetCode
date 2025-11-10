class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        m, n = len(nums1), len(nums2)
        total = m + n
        i = j = 0
        merged = []

        while i < m and j < n:
            if nums1[i] < nums2[j]:
                merged.append(nums1[i])
                i += 1
            else:
                merged.append(nums2[j])
                j += 1

        merged += nums1[i:] + nums2[j:]

        if total % 2 == 1:
            return merged[total // 2]
        else:
            return merged[total // 2 - 1]

    def findMedianSortedArrays2(self, nums1, nums2):
        merged = sorted(nums1 + nums2)
        n = len(merged)

        if n % 2 == 1:
            return merged[n//2]
        else:
            return merged[n//2 - 1]


if __name__ == "__main__":
    sol = Solution()
    num1 = [1,3,8]
    num2 = [7,9,10,11]

    print(sol.findMedianSortedArrays(num1,num2))