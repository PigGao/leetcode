class Solution{
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        vector<int> level;
        list<TreeNode*> cur,next;
        if(root==nullptr)
            return result;
        cur.push_back(root);
        while(!cur.empty())
        {
            while(!cur.empty())
            {
                TreeNode *node = cur.front();
                cur.pop_front();
                level.push_back(node->val);
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
                
            }
            result.push_back(level);
            level.clear();
            swap(cur,next);
        }
        return result;
    }
};
/*#include <cstdio>
#include <cstdlib>
#include <stack>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
#include <map>
#include <list>
#include <algorithm>
#include <ctime>
#include <string>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):val(val), left(NULL),right(NULL){} ; 
};

TreeNode *constructTree(int *dat , int len)
{
    TreeNode *root = NULL;
    int index = 0;
    if(len > 0)
        root = new TreeNode(dat[index]);
    else
        return NULL;

    list<TreeNode *> node;
    node.push_back(root);
    index ++;
    while(index < len)
    {
        if(!node.empty())
        {
            TreeNode *root = node.front();
            if(index < len )
            {
                if(dat[index] != '#')
                {
                    root->left = new TreeNode(dat[index]);  
                    node.push_back(root->left);
                }
                index ++;
            }
            if(index < len )
            {
                if(dat[index] != '#')
                {
                    root->right = new TreeNode(dat[index]); 
                    node.push_back(root->right);
                }
                index ++;
            }
            node.pop_front();
        }
    }

    return root;
}

void traversal(TreeNode *node)
{
    if(!node)
        return;
    cout <<"\t"<< node->val;
    traversal(node->left);
    traversal(node->right);
}
void printvector(const vector<vector<int> > &v)
{
    for(int i=0;i<v.size();++i)
    {
        for(int j=0;j<v[i].size();++j)
            cout<<v[i][j]<<',';
        cout<<endl;
    }

}
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        std::vector<vector<int> > result;
        if(root==nullptr) return result;
        std::vector<int> level;
        queue<TreeNode *> current,next;
        current.push(root);
        while(!current.empty())
        {
            while(!current.empty())
            {
                TreeNode *node=current.front();
                current.pop();
                level.push_back(node->val);
                if(node->left!=nullptr) next.push(node->left);
                if(node->right!=nullptr) next.push(node->right);

            }

            result.push_back(level);
            level.clear();
            swap(current,next);

        }
        return result;
    }

};



int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout <<"Usage: ./createTreev 30 50 50 2 3 3 2"<<endl;
        exit(1);
    }

    int len = argc -1 ;
    cout << len <<endl;

    int *data = (int *)malloc(sizeof(int) * len);
    memset(data, 0, sizeof(char)*len);
    for(int i=1; i<argc; i++)
    {
        if(*argv[i] != '#')
            data[i-1] = atoi(argv[i]) ;
        else
            data[i-1] = '#';
    }
    for(int i=0; i < len ; i++)
        cout <<"\t"<< data[i] ;
    cout << endl;
    cout << endl;

    TreeNode *tree = NULL;
    tree = constructTree(data, len);

    //traversal(tree);
    //cout << endl;

    Solution s;
    printvector(s.levelOrder(tree));
}
*/
