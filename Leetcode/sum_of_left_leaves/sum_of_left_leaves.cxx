/* 

404. 左叶子之和

计算给定二叉树的所有左叶子之和。
difficulty: easy.

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 
通过次数70,700提交次数124,800
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
using std::cout;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class sum_of_left_leaves
{
public:
  int sumOfLeftLeaves(TreeNode *root)
  {
    return calc(root, 0, false);
  }

  int calc(TreeNode *root, int sum, bool con)
  {
    if (!root)
      return 0;
    if (!root->left && !root->right && con)
      return sum + root->val;
    return sum + calc(root->left, sum, true) + calc(root->right, sum, false);
  }
};

// 还行.
// Tue,March2,2021
// 13:06:55:83:637502872150836772