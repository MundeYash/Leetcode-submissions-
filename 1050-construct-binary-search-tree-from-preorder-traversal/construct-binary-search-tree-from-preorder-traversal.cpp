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

int search(vector<int> in, int element)
{
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}
TreeNode *solve2(vector<int> pre, vector<int> in, int n, int &index, int inorderStart, int inorderEnd)
{
    if (inorderStart > inorderEnd || index >= n)
        return NULL;

    int element = pre[index++];

    TreeNode *root = new TreeNode(element);
    int position = search(in, element);
    root->left = solve2(pre, in, n, index, inorderStart, position - 1);
    root->right = solve2(pre, in, n, index, position + 1, inorderEnd);

    return root;
}

    TreeNode* bstFromPreorder(vector<int>& pre) {
         // create tree from the inorder(get by sorting the preorder ) and pre order

    // time : O(n logn )  , space : O(1);

    // step 1 : find the inorder traversal by sorting preorder
    vector<int> in = pre;
    sort(in.begin(), in.end());

    // step 2 : appy the concept of construct tree form inorder and pre order
    int preorderIndex = 0;
    int n = in.size();
    int inorderStart = 0, inorderEnd = n - 1;
    int index = 0;

    TreeNode *root = solve2(pre, in, n, index, inorderStart, inorderEnd);
    return root;
    }
};