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

#include <iostream>
#include <vector>
using std::cout;
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

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        vector<TreeNode *> stack;
        auto it = root;
        TreeNode *prev = nullptr;

        while (it != nullptr || !stack.empty())
        {
            stack.push_back(it);
            
            
        }
    }
};

#pragma region
int main()
{
    // contructor binary tree.
    TreeNode *root = new TreeNode(1);
    TreeNode r1(2);
    TreeNode rl2(3);
    root->right = &r1;
    r1.left = &rl2;

    binary_tree_postorder_traverser btpt;

// #define DEBUG
#ifdef DEBUG

    int i = 42;
    auto ds = __DATE__;
    auto ts = __TIME__;
    cout << ds << "\n";
    cout << ts << "\n";
    cout << "compile time: " << ds << " " << ts << "\n";

#endif

    // auto ans = btpt.postorderTraversal(root);

    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
}
#pragma endregion

// binary tree postorder traversal 非递归写法参考.
#pragma region REFERENCE CODE
#define REFERENCE
#ifndef REFERENCE

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev)
            {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            }
            else
            {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};

#endif
#pragma endregion

//
//
