class Solution:
    def isPalindrome(self, x:int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        reversed_half = 0

        while x > reversed_half:
            pop = x % 10
            x //= 10
            reversed_half =  reversed_half * 10 + pop


        return reversed_half == x or reversed_half // 10 == x



if __name__ == "__main__":
    sol = Solution()
    print(sol.isPalindrome(123))
    print(sol.isPalindrome(0))
    print(sol.isPalindrome(-1))
    print(sol.isPalindrome(12321))