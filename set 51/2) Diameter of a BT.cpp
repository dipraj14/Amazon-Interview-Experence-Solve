// https://leetcode.com/problems/diameter-of-binary-tree/
/*
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
 This path may or may not pass through the root.
 */

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
public:
    int helper(TreeNode* root, int &dia){
        if(!root) return 0;
        
        int lh  = helper(root -> left, dia);
        int rh  = helper(root -> right, dia);
        dia = max(dia , lh + rh);
        
        int hight = 1 + max(lh, rh);
        return hight;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        helper(root, dia);
        return dia;
    }
};