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
    int preIdx = 0;//indicies for the root of the subtrees
    int inIdx = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //First element of the preorder is the root. 
        //Then in the inorder traversal the left and right halves on either side of the root element are the left and right subtrees.
        //We can use this idea in a recursive fassion: Go down the subtree, first element in preorder (for the nth subtree, we move up one index every subtree split.) is the root of the subtree, then we can formulate the tree.

        return dfs(preorder, inorder, INT_MAX);
    }

//We can have a dfs that will go up the preorder list each time to get the root of the new subtree. (root, left , right)
//We have a limit the stops the left subtree since we know it is complete
    TreeNode* dfs(vector<int> & preorder, vector<int>& inorder, int limit) {
         if (preIdx >= preorder.size()) return nullptr; //gone through whole list

         if (inorder[inIdx] == limit) {
            inIdx++;
            return nullptr;
         }

        
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        root->left = dfs(preorder, inorder, root->val); 
        root->right = dfs(preorder, inorder, limit);
        return root; //return the subtree/tree root
    }

};
