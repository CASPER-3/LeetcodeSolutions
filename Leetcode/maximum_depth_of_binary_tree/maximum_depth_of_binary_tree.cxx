/* 
104. 二叉树的最大深度.

difficulty: easy

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

通过次数354,779提交次数468,075
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <algorithm>
using std::max;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class maximum_depth_of_binary_tree
{

public:
    int maxDepth(TreeNode *root)
    {
        return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};

// Mon,March1,2021
// 15:37:45:658:637502098656583007
