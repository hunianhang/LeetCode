class Solution:
    def strStr(self, haystack, needle):

        if not needle:
            return 0

        n, m = len(haystack), len(needle)

        for i in range(n - m + 1):
            if haystack[i:i + m] == needle:
                return i

        return -1

if __name__ == '__main__':
    haystack = "hello world"
    needle = "world"

    s = Solution()
    index = s.strStr(haystack, needle)
    print(index)