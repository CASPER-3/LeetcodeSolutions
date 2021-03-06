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
    }

    void morrisTraversal(TreeNode *root)
    {
        TreeNode *temp = root;
        
        if(!root->left)
        {
            ans.push_back(root->right->val);
        }
    }
};

/* 

方法三：Morris 遍历
思路与算法

有一种巧妙的方法可以在线性时间内，只占用常数空间来实现后序遍历。这种方法由 J. H. Morris 在 1979 年的论文「Traversing Binary Trees Simply and Cheaply」中首次提出，因此被称为 Morris 遍历。

Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其后序遍历规则总结如下：

新建临时节点，令该节点为 root；

如果当前节点的左子节点为空，则遍历当前节点的右子节点；

如果当前节点的左子节点不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点；

如果前驱节点的右子节点为空，将前驱节点的右子节点设置为当前节点，当前节点更新为当前节点的左子节点。

如果前驱节点的右子节点为当前节点，将它的右子节点重新设为空。倒序输出从当前节点的左子节点到该前驱节点这条路径上的所有节点。当前节点更新为当前节点的右子节点。

重复步骤 2 和步骤 3，直到遍历结束。

这样我们利用 Morris 遍历的方法，后序遍历该二叉搜索树，即可实现线性时间与常数空间的遍历。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/er-cha-shu-de-hou-xu-bian-li-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */