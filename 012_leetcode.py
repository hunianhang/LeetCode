class Solution:
    def intToRoman(self, nums:int)-> str:
        val = [
            1000,900,500,400, 100, 90, 50, 40, 10,9,5, 4,1
        ]

        syms = [
            "M", "CM", "D", "CD", "C", "XC",
            "L", "XL", "X", "IX", "V", "IV", "I"
        ]
        romNum = ""

        for i in range(len(val)):
            while nums > val[i]:
                nums -= val[i]
                romNum += syms[i]

        return romNum


if __name__ == "__main__":
    s = Solution()
    print(s.intToRoman(3))  # 输出: "III"
    print(s.intToRoman(4))  # 输出: "IV"
    print(s.intToRoman(9))  # 输出: "IX"
    print(s.intToRoman(58))  # 输出: "LVIII"
    print(s.intToRoman(1994))  # 输出: "MCMXCIV"

