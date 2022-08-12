// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTreeHelp(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int> &hash){
        
        if(preStart > preEnd or inStart > inEnd){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int rootIdx = hash[preorder[preStart]];
        int numsleft = rootIdx - inStart;
        
        root -> left = buildTreeHelp(preorder, preStart + 1, preStart + numsleft, inorder, inStart , rootIdx - 1, hash);
        
        root -> right = buildTreeHelp( preorder, preStart + numsleft + 1, preEnd, inorder , rootIdx + 1, inEnd, hash);
        
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int> hash;
        for(int i=0; i<inorder.size(); i++){
            hash[inorder[i]] = i; 
        }
        
        
        TreeNode* newRoot = buildTreeHelp(preorder, 0, preorder.size() - 1, 
                                         inorder, 0, inorder.size() - 1, hash);
        
        return newRoot;
    }
};