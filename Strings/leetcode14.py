from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""

        prefix = strs[0]

        for i in range(1, len(strs)):
            s = strs[i]
            j = 0
            while j < len(prefix) and j < len(s) and prefix[j] == s[j]:
                j += 1
            prefix = prefix[:j]
            if prefix == "":
                break

        return prefix


if __name__ == "__main__":
    solution = Solution()
    strs = ["flower", "flow", "flight"]
    print(solution.longestCommonPrefix(strs))
    strs = ["dog", "racecar", "car"]
    print(solution.longestCommonPrefix(strs))
