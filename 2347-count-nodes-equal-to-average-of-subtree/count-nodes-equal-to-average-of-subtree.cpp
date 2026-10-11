/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int matchcount=0;
    pair<int,int> dfs(TreeNode* node){
        if(node==nullptr){
            return{0,0};
        }

        auto left=dfs(node->left);
        auto right=dfs(node->right);
        int sum=left.first+right.first+node->val;
        int currentcount=left.second+right.second+1;

        if(sum/currentcount == node->val){
            matchcount++;
        }
        return {sum,currentcount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        matchcount=0;
        dfs(root);
        return matchcount;    
    }
};