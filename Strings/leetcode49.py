from ast import List
import collections
from typing import List

def groupAnagrams(strs: List[str]) -> List[List[str]]:
        dict = collections.defaultdict(list)
        for s in strs:
            key=''.join(sorted(s))
            dict[key].append(s)
        return dict.values()

if __name__ == "__main__":
    print(groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
    print(groupAnagrams([""]))
    print(groupAnagrams(["a"]))