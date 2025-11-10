class Solution:
    def isValid(self, s:str) -> bool:
        stack = []

        mapping = {
            ')':'(',
            '}':'{',
            ']':'['
        }

        for c in s:
            if c in mapping:
                top = stack.pop() if stack else None
                if mapping[c] != top:
                    return False
            else:
                stack.append(c)

        return  not stack


if __name__ == '__main__':
    s = Solution()
    print(s.isValid("()"))  # True
    print(s.isValid("()[]{}"))  # True
    print(s.isValid("(]"))  # False
    print(s.isValid("([{}])"))  # True
    print(s.isValid("((("))  # False