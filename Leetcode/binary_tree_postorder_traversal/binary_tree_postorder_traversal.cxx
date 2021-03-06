/* 

145. 二叉树的后序遍历

给定一个二叉树，返回它的 后序 遍历。
difficulty: medium

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

通过次数192,104提交次数258,905
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


 */

#include <vector>
using std::vector;

struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class binary_tree_postorder_traverser
{
private:
   vector<int> ans;

public:
   vector<int> postorderTraversal(TreeNode *root)
   {
      dfs(root);
      return ans;
   }

   void dfs(TreeNode *root)
   {
      if (!root)
      {
         return;
      }
      dfs(root->left);
      dfs(root->right);
      ans.push_back(root->val);
   }
};

// binary tree postorder traversal in Recursion.
// Tue,March2,2021
// 13:22:04:160:637502881241602922
