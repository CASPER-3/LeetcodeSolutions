/* 

输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

 

提示：

节点总数 <= 10000
注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

通过次数100,586提交次数127,494

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <cstdlib>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class maximum_depth_of_binary_tree_lcof
{
private:
  int depth=0;

public:
  int maxDepth(TreeNode *root)
  {
    dfs(root,1);
    return depth;
  }
  void dfs(TreeNode *root, int dep)
  {
    if (!root)
    {
      return;
    }
    depth = dep > depth ? dep : depth;
    dfs(root->left, dep + 1);
    dfs(root->right, dep + 1);
  }
};

// Mon,March1,2021
// 15:19:23:463:637502087634633568