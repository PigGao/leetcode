class Solution {
public:
    int res;
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
private:
    int dfs(TreeNode* node)
    {
        if(node==NULL)
            return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        res = res + abs(L)+abs(R);
        return node->val+L+R-1;
    }
};
