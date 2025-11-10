class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        prefix = strs[0]

        for s in strs[1:]:
            while not s.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""

        return prefix

    def longestComonPrefix2(self,strs:list[str]) -> str:
        if strs == []:
            return ""

        def commonPrefix(a,b):
            min_len = min(len(a),len(b))

            for i in range(min_len):
                if a[i] != b[i]:
                    return a[:i]

            return a[:min_len]


        prefix = strs[0]

        for i in range(1,len(strs)):
            prefix = commonPrefix(prefix,strs[i])
            if not prefix:
                break
        return prefix

if __name__ == "__main__":
    sol = Solution()
    strs = ["flower", "flow", "flight"]
    print(sol.longestCommonPrefix(strs))
