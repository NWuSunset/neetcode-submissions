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
    int index  = 0; 
    int answer;
    int kthSmallest(TreeNode* root, int k) {
        //kth smallest value (1 indexed, root index 1). of the binary serach tree.
        //Binary search tree is sorted, the minimum (smallest value) will just be on the very left of the tree

        //We can do a in order traversal to get the kth smallest element (left, root, right) since that effecitvely goes through the binary tree in order, once we hit the kth smallest stop the traversal
        //We visit k nodes in the traversa
        dfs_inorder(root, k);
        return answer;
    }

    void dfs_inorder(TreeNode* node, int k) {
        //base case 
        if (!node) return;

        //go inorder traversal
        dfs_inorder(node->left, k); //go left subtree first

        //now 'visit' the node (root 2nd)
        index++;
        if (index == k) { //if index == k then this node is the k smallest node.
            answer = node->val;
            return;
        }

        dfs_inorder(node->right, k); //go to right subtree
    }


};
