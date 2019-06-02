class Solution(object):
    
    def dfs(self,cur,nums,a,result):
        if cur == len(nums):
            result.append(a)
        for x in nums:
            ok=1
            for i in range(cur):
                if(a[i]==x):
                    ok=0;
            if ok==1:
                if len(a)==cur:
                    a.append(x)
                else:
                    a[cur] = x
                self.dfs(cur+1,nums,a[0:cur+1],result)
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        a = []
        self.dfs(0,nums,[],result)
        return result