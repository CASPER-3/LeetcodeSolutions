/* 

给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.
通过次数83,903提交次数125,908
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::find;
using std::reverse;
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

class sum_root_to_leaf_numbers
{

private:
public:
  vector<int> recorder;
  vector<int> depth;
  int maxdepth = 0;

  int sumNumbers(TreeNode *root)
  {
    if(!root->left&&!root->right)
    {
      return root->val;
    }
    dfs(root, 0);
    reverse(recorder.begin(), recorder.end());
    reverse(depth.begin(), depth.end());
    int sum = 0;
    for (int i = 0; i < recorder.size() - 1; ++i)
    {
      if (i >= 1 && depth[i - 1] > depth[i])
      {
        continue;
      }

      int k = 1;
      int temp = depth[i];
      int pos = i;
      while (temp >= 0)
      {
        sum += recorder[pos] * k;
        k *= 10;
        pos = find(depth.begin() + i + 1, depth.end(), temp - 1) - depth.begin();
        --temp;
      }
    }

    return sum;
  }

  void dfs(TreeNode *root, int dep)
  {
    if (!root)
    {
      return;
    }

    TreeNode *it = root;
    cout << it->val << "\n";
    recorder.push_back(it->val);
    depth.push_back(dep);
    maxdepth = dep > maxdepth ? dep : maxdepth;

    dfs(root->left, dep + 1);
    dfs(root->right, dep + 1);
  }
};

int main()
{
  // construct binary tree.
  TreeNode *root = new TreeNode(4);
  TreeNode *l1 = new TreeNode(9);
  TreeNode *r1 = new TreeNode(0);
  TreeNode *ll1 = new TreeNode(5);
  TreeNode *lr1 = new TreeNode(1);
  root->left = l1;
  root->right = r1;
  l1->left = ll1;
  l1->right = lr1;

  // construct another binary tree.
  TreeNode *root1 = new TreeNode(1);
  TreeNode *nl1 = new TreeNode(2);
  TreeNode *nr1 = new TreeNode(3);
  root1->left = nl1;
  root1->right = nr1;

  sum_root_to_leaf_numbers srtln;
  // srtln.dfs(root, 0);

  // cout << "---------------------------------------------------------\n";
  // for (auto i : srtln.recorder)
  // {
  //   cout << i << " ";
  // }

  // cout << "\n";

  // for (auto i : srtln.depth)
  // {
  //   cout << i << " ";
  // }

  // cout << "\n";
  // cout << srtln.maxdepth;
  cout << "---------------------------------------------------------\n";
  cout << srtln.sumNumbers(root1) << "\n";
}


// 自己写的像个沙口一样的解法.
// Mon,March1,2021
// 08:58:24:768:637501859047682154
