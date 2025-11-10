class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_set = set()
        left = 0
        right = 0
        max_len = 0

        for right in range(len(s)):
            if s[right] in char_set:
                char_set.remove(s[left])
                left += 1
            char_set.add(s[right])
            max_len = max(max_len, right - left + 1)

        return max_len
    def lengthOfLongestSubstring2(self, s: str) -> int:
        last = {}
        start = 0
        max_len = 0

        for i,ch in enumerate(s):
            if ch in last and last[ch] >= start:
                start = last[ch] + 1
            last[ch] = i
            max_len = max(max_len, i - start + 1)

        return max_len


# if __name__ == "__main__":
#     s = Solution()
#
#     s1 = "abcabcbb"
#     print(f'input: {s1}')
#     print(f'Output: {s.lengthOfLongestSubstring2(s1)}')
#
#     s2 = 'bbbb'
#     print(f'input: {s2}')
#     print(f'Output: {s.lengthOfLongestSubstring2(s2)}')

if __name__ == "__main__":
    sol = Solution()

    tests = ["abcabcbb", "bbbbbb", "pwwke","dvdf",""," "]

    for t in tests:
        print(t,"->",sol.lengthOfLongestSubstring2(t))
