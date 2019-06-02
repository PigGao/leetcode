class Solution(object):
    
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort(reverse=False)
        def dfs(cur,n,num,a,ans):
            if n == cur:
                ans.append(a)
                return
            for i in range(len(num)):
                ok=1
                if i>0:
                    if num[i]==num[i-1]:
                        ok=0
                        continue
                if ok==1:
                    if len(a) == cur:
                        a.append(num[i])
                        dfs(cur+1,n,num[0:i]+num[i+1:],a[:cur+1],ans)  
                    else:
                        a[cur] = num[i]
                        
                        dfs(cur+1,n,num[0:i]+num[i+1:],a[:cur+1],ans)   
        ans=[]
        n = len(nums)
        dfs(0,n,nums,[],ans)
        return ans