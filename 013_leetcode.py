class Solution:
    def romanToInt(self, s:str) -> int:
        roman = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }

        total = 0

        for i in range(len(s) - 1):
            if roman[s[i]] < roman[s[i+1]]:
                total -= roman[s[i]]
            else:
                total += roman[s[i]]

        total += roman[s[-1]]

        return total

if __name__ == "__main__":
    s = Solution()
    print(s.romanToInt("III"))  # 输出: 3
    print(s.romanToInt("IV"))  # 输出: 4
    print(s.romanToInt("IX"))  # 输出: 9
    print(s.romanToInt("LVIII"))  # 输出: 58
    print(s.romanToInt("MCMXCIV"))  # 输出: 1994