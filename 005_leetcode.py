# nested function
# class Solution:
#     def longestPalindrome(self,s):
#         def expand(left, right):
#             print(f"expand was called, parameters: left={left}, right={right}")
#
#         for i in range(len(s)):
#             expand(i,i)
#             expand(i,i+1)



# function parameters and local variable
class Solution2:
    def longestPalindrome(self, s:str)->str:
        if len(s) < 2:
            return s

        start = 0  #the starting point of the longest palindrome
        max_len = 1

        def expand(left, right):
            nonlocal start, max_len
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1

                if right - left - 1 > max_len:
                    start = left + 1
                    max_len = right - left - 1

        for i in range(len(s)):
            expand(i,i)
            expand(i,i+1)
        print("test")
        print(f"longest palindrome is:{max_len}")
        print(f"longest palindrome substring is: {s[start:start + max_len]}")
        return s[start:start + max_len]

if __name__ == "__main__":
    sol = Solution2()
    sol.longestPalindrome("a")