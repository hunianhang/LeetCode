class Solution:
    def lengthOfLengestSubstring(self, s:str) -> int:
        seen = {}
        start = 0
        max_len = 0
        max_str = ""

        for i, ch in enumerate(s):
            if ch in seen and seen[ch] >= start:
                start = seen[ch] + 1

            seen[ch] = i

            cur_len = i - start + 1
            if cur_len > max_len:
                max_len = cur_len
                max_str = s[start:i + 1]

        print(f"longest substring: {max_str}")

        return max_len


if __name__ == "__main__":
    sol = Solution()
    tests = ["abcabcbb", "bbbbbb", "pwwke","dvdf",""," "]

    for t in tests:
        print(t,"->", sol.lengthOfLengestSubstring(t))