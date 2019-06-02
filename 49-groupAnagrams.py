from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        tmp = defaultdict(list)
        for s in strs:
            tmp[tuple(sorted(s))].append(s)
        ans=[]
        for k in tmp:
            ans.append(tmp[k])
        return ans