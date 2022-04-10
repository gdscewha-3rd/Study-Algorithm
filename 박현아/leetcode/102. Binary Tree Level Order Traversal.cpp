//220408
//leetcode #102 Binary Tree Level Order Traversal.cpp /Medium
//https://leetcode.com/problems/binary-tree-level-order-traversal/

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
#define MAX 2001

class Solution {
public:
    vector<int> results[MAX];
    
    void levOrder(TreeNode* root, int level){
        if(!root)
            return;
        //push root
        results[level].push_back(root->val);
        levOrder(root->left,level+1);
        levOrder(root->right,level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        levOrder(root,0);
        
        vector<vector<int>> r;
        for(int i=0; i<MAX; i++){
            if(results[i].empty())
                break;
            r.push_back(results[i]);
        }
        return r;
    }
};
