// https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401

#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
     if(root == NULL) return ans;
    queue<pair<TreeNode<int>*, int>> q;
    map<int, TreeNode<int>*> mp;
    q.push({root, 0});
    while(!q.empty()){
        TreeNode<int> * node = q.front().first;
        int var = q.front().second;
        q.pop();
        if(mp.find(var) == mp.end()){
            mp[var] = node;
        }
        if(node -> left ){
            q.push({node->left, var - 1});
        }
        if(node -> right){
            q.push({node -> right, var + 1});
        }
    }
    
    for(auto it: mp){
        ans.push_back(it.second -> val);
    }
    
    return ans;
}